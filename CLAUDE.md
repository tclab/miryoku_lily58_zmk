# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## What This Repo Is

A fork of [Miryoku ZMK](https://github.com/manna-harbour/miryoku_zmk) — ZMK firmware configuration for a **Lily58 split keyboard** with a **nice!nano v2** controller and **nice!view** display, using the Miryoku ergonomic keyboard layout.

There is no local build toolchain. All firmware is built via **GitHub Actions** using the `zmkfirmware/zmk-build-arm:stable` Docker container.

## Building Firmware

**The only way to build is via GitHub Actions.** There is no `make`, `west`, or local build command to run.

To trigger a build for the Lily58:
1. Go to the repo's **Actions** tab on GitHub
2. Select the **"Lily58 nice_nano_v2 nice_view"** workflow (`lily58-nice_nano_v2-nice_view.yml`)
3. Click **Run workflow**
4. Download the resulting `.uf2` artifact — one per half (`lily58_left` and `lily58_right`)

To build with custom options, use **Build Inputs** (`build-inputs.yml`) or copy an example workflow from `.github/workflows/examples/` and push it.

## Flashing Firmware

1. Double-tap the reset button on one half — it mounts as a USB drive
2. Drag the corresponding `.uf2` file onto it
3. Repeat for the other half
4. Flash the left half first, then reconnect both halves

## Architecture

### How a keymap is composed

Each keyboard's keymap is assembled from three layers of includes, exemplified by `config/lily58.keymap`:

```
custom_config.h         ← your #define overrides (currently empty)
    ↓
miryoku/mapping/58/lily58.h  ← maps Miryoku's 36 logical keys onto the 58-key physical layout
    ↓
miryoku/miryoku.dtsi    ← the full Miryoku keymap (layers, behaviors, combos, mouse keys)
```

`miryoku.dtsi` pulls in `miryoku.h`, which resolves which layers and behaviors to include based on `#define` flags set in `custom_config.h` or injected by the workflow.

### Customisation via `#define` flags

Options are activated by adding `#define` lines to `miryoku/custom_config.h` for local builds, or by passing them as workflow inputs. Key flags:

| Flag | Effect |
|---|---|
| `MIRYOKU_ALPHAS_QWERTY` | Switch alphas layer to QWERTY (default is Colemak-DH) |
| `MIRYOKU_NAV_VI` | Vi-style nav keys |
| `MIRYOKU_CLIPBOARD_MAC` | Mac clipboard shortcuts |
| `MIRYOKU_CLIPBOARD_WIN` | Windows clipboard shortcuts |
| `MIRYOKU_LAYERS_FLIP` | Flip Nav to left hand |
| `MIRYOKU_MAPPING_EXTENDED_THUMBS` | Alternative thumb cluster mapping |

### Workflow options → `#define` translation

`main.yml` takes workflow inputs (`alphas`, `nav`, `clipboard`, etc.) and translates them into `#define MIRYOKU_ALPHAS_QWERTY`-style flags prepended to `custom_config.h` before building. The `custom_config` input lets you inject arbitrary `#define` lines directly.

### Mapping files (`miryoku/mapping/<N>/`)

Each subdirectory is named after the key count. The `.h` files in them define `MIRYOKU_LAYERMAPPING_<LAYER>` macros that place Miryoku's 36 logical bindings onto the physical key positions of that keyboard. For the Lily58 (58 keys), extra positions are filled with `U_NP` (not present), `U_NA` (not available), or `U_NU` (not used).

### Lily58 physical layout

The Lily58 has 58 physical keys but Miryoku only uses **36 of them** — the inner 3×5 alpha grid plus 3 thumb keys per side. The top number row, outer pinkie columns, and the 4th/5th thumb positions are all `&none` (`XXX` in `miryoku/mapping/58/lily58.h`).

### The Lily58-specific workflow

`.github/workflows/lily58-nice_nano_v2-nice_view.yml` builds both halves (`lily58_left` and `lily58_right`) with the `nice_view_adapter nice_view` shield combo and QWERTY alphas. Modify this file to change the default build options for this keyboard.

## Current Active Configuration

`custom_config.h` is empty. The only active non-default option is set in the workflow:
- `alphas: QWERTY` → `MIRYOKU_ALPHAS_QWERTY` defined at build time

All other options are at their defaults (Colemak-DH tap layer, home-position nav, CUA clipboard).

## Layer Map

Layers are accessed by holding a thumb key on the BASE layer:

| Thumb key (hold) | Layer  | Purpose                              |
|------------------|--------|--------------------------------------|
| `ESC`            | MEDIA  | Media, RGB, Bluetooth, volume        |
| `SPC`            | NAV    | Arrows, home/end, page up/down       |
| `TAB`            | MOUSE  | Mouse movement, scroll, buttons      |
| `RET`            | SYM    | Symbols (shifted punctuation)        |
| `BSP`            | NUM    | Numbers and unshifted punctuation    |
| `DEL`            | FUN    | F-keys, print screen, pause          |
| `Z` / `/`        | BUTTON | Clipboard, undo/redo, mouse buttons  |

From any utility layer, the right-hand inner column provides layer navigation (`→BASE`, `→TAP`, `→EXTRA`) and `Boot` (enter bootloader).

## Bluetooth Pairing

Bluetooth is managed from the **MEDIA layer** (hold `ESC`):

- **Select profile**: press `BT0`–`BT3` (bottom row, right hand) — four independent pairing slots
- **Pair new device**: select an unused slot, then pair from the host device; the keyboard advertises as "Lily58"
- **Switch device**: select the slot for the target device — it reconnects automatically
- **Toggle USB/BT output**: press `OutTg` (bottom row, right hand, leftmost key)

There is no `BT_CLR` in the default layout. To clear a pairing slot, add it via `custom_config.h` with a custom layer binding.
