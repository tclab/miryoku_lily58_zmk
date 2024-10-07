// Copyright 2022 Manna Harbour
// https://github.com/manna-harbour/miryoku
// generated -*- buffer-read-only: t -*-

#pragma once

#include "miryoku_layer_alternatives.h"

// Base
#if !defined(MIRYOKU_LAYER_BASE)
  #define MIRYOKU_LAYER_BASE MIRYOKU_ALTERNATIVES_BASE_QWERTY
#endif
#if !defined(MIRYOKU_LAYERMAPPING_BASE)
  #define MIRYOKU_LAYERMAPPING_BASE MIRYOKU_MAPPING
#endif

// Extra
#if !defined(MIRYOKU_LAYER_EXTRA)
  #define MIRYOKU_LAYER_EXTRA MIRYOKU_ALTERNATIVES_BASE_QWERTY
#endif
#if !defined(MIRYOKU_LAYERMAPPING_EXTRA)
  #define MIRYOKU_LAYERMAPPING_EXTRA MIRYOKU_MAPPING
#endif

// Tap
#if !defined(MIRYOKU_LAYER_TAP)
  #define MIRYOKU_LAYER_TAP MIRYOKU_ALTERNATIVES_TAP_QWERTY
#endif
#if !defined(MIRYOKU_LAYERMAPPING_TAP)
  #define MIRYOKU_LAYERMAPPING_TAP MIRYOKU_MAPPING
#endif

// Button
#if !defined(MIRYOKU_LAYER_BUTTON)
  #define MIRYOKU_LAYER_BUTTON MIRYOKU_ALTERNATIVES_BUTTON
#endif
#if !defined(MIRYOKU_LAYERMAPPING_BUTTON)
  #define MIRYOKU_LAYERMAPPING_BUTTON MIRYOKU_MAPPING
#endif

// Navigation
#if !defined(MIRYOKU_LAYER_NAV)
  #define MIRYOKU_LAYER_NAV MIRYOKU_ALTERNATIVES_NAV
#endif
#if !defined(MIRYOKU_LAYERMAPPING_NAV)
  #define MIRYOKU_LAYERMAPPING_NAV MIRYOKU_MAPPING
#endif

// Mouse
#if !defined(MIRYOKU_LAYER_MOUSE)
  #define MIRYOKU_LAYER_MOUSE MIRYOKU_ALTERNATIVES_MOUSE
#endif
#if !defined(MIRYOKU_LAYERMAPPING_MOUSE)
  #define MIRYOKU_LAYERMAPPING_MOUSE MIRYOKU_MAPPING
#endif

// Media
#if !defined(MIRYOKU_LAYER_MEDIA)
  #define MIRYOKU_LAYER_MEDIA MIRYOKU_ALTERNATIVES_MEDIA
#endif
#if !defined(MIRYOKU_LAYERMAPPING_MEDIA)
  #define MIRYOKU_LAYERMAPPING_MEDIA MIRYOKU_MAPPING
#endif

// Numbers
#if !defined(MIRYOKU_LAYER_NUM)
  #define MIRYOKU_LAYER_NUM MIRYOKU_ALTERNATIVES_NUM
#endif
#if !defined(MIRYOKU_LAYERMAPPING_NUM)
  #define MIRYOKU_LAYERMAPPING_NUM MIRYOKU_MAPPING
#endif

// Symbols
#if !defined(MIRYOKU_LAYER_SYM)
  #define MIRYOKU_LAYER_SYM MIRYOKU_ALTERNATIVES_SYM
#endif
#if !defined(MIRYOKU_LAYERMAPPING_SYM)
  #define MIRYOKU_LAYERMAPPING_SYM MIRYOKU_MAPPING
#endif

// Function
#if !defined(MIRYOKU_LAYER_FUN)
  #define MIRYOKU_LAYER_FUN MIRYOKU_ALTERNATIVES_FUN
#endif
#if !defined(MIRYOKU_LAYERMAPPING_FUN)
  #define MIRYOKU_LAYERMAPPING_FUN MIRYOKU_MAPPING
#endif
