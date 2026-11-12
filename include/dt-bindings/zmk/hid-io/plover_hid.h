/*
 * Copyright (c) 2024 The ZMK Contributors
 *
 * SPDX-License-Identifier: MIT
 */

#pragma once

#include <dt-bindings/zmk/keys.h>

/*
 * Plover HID steno keys.
 *
 * Each PLV_* name expands to the two parameters of the &plv behavior. The
 * first is a keyboard key that ZMK Studio draws on the key as its label. The
 * second, PLV_ID_*, is the bit index in the 64-bit Plover HID report.
 *
 * The indices follow the standard steno layout:
 *   S- T- K- P- W- H- R- A O * E U -F -R -P -B -L -G -T -S -D -Z #
 *
 * Indices 23-63 are a second S, extra stars, extra number keys and 26
 * spare keys.
 */

#define PLV_ID_SL 0
#define PLV_SL S PLV_ID_SL
#define PLV_ID_TL 1
#define PLV_TL T PLV_ID_TL
#define PLV_ID_KL 2
#define PLV_KL K PLV_ID_KL
#define PLV_ID_PL 3
#define PLV_PL P PLV_ID_PL
#define PLV_ID_WL 4
#define PLV_WL W PLV_ID_WL
#define PLV_ID_HL 5
#define PLV_HL H PLV_ID_HL
#define PLV_ID_RL 6
#define PLV_RL R PLV_ID_RL
#define PLV_ID_A 7
#define PLV_A A PLV_ID_A
#define PLV_ID_O 8
#define PLV_O O PLV_ID_O
#define PLV_ID_ST 9
#define PLV_ST KP_MULTIPLY PLV_ID_ST
#define PLV_ID_E 10
#define PLV_E E PLV_ID_E
#define PLV_ID_U 11
#define PLV_U U PLV_ID_U
#define PLV_ID_FR 12
#define PLV_FR F PLV_ID_FR
#define PLV_ID_RR 13
#define PLV_RR R PLV_ID_RR
#define PLV_ID_PR 14
#define PLV_PR P PLV_ID_PR
#define PLV_ID_BR 15
#define PLV_BR B PLV_ID_BR
#define PLV_ID_LR 16
#define PLV_LR L PLV_ID_LR
#define PLV_ID_GR 17
#define PLV_GR G PLV_ID_GR
#define PLV_ID_TR 18
#define PLV_TR T PLV_ID_TR
#define PLV_ID_SR 19
#define PLV_SR S PLV_ID_SR
#define PLV_ID_DR 20
#define PLV_DR D PLV_ID_DR
#define PLV_ID_ZR 21
#define PLV_ZR Z PLV_ID_ZR
#define PLV_ID_NM 22
#define PLV_NM KP_NUM PLV_ID_NM
#define PLV_ID_SL2 23
#define PLV_SL2 S PLV_ID_SL2
#define PLV_ID_ST2 24
#define PLV_ST2 KP_MULTIPLY PLV_ID_ST2
#define PLV_ID_ST3 25
#define PLV_ST3 KP_MULTIPLY PLV_ID_ST3
#define PLV_ID_ST4 26
#define PLV_ST4 KP_MULTIPLY PLV_ID_ST4
#define PLV_ID_NM2 27
#define PLV_NM2 KP_NUM PLV_ID_NM2
#define PLV_ID_NM3 28
#define PLV_NM3 KP_NUM PLV_ID_NM3
#define PLV_ID_NM4 29
#define PLV_NM4 KP_NUM PLV_ID_NM4
#define PLV_ID_NM5 30
#define PLV_NM5 KP_NUM PLV_ID_NM5
#define PLV_ID_NM6 31
#define PLV_NM6 KP_NUM PLV_ID_NM6
#define PLV_ID_NM7 32
#define PLV_NM7 KP_NUM PLV_ID_NM7
#define PLV_ID_NM8 33
#define PLV_NM8 KP_NUM PLV_ID_NM8
#define PLV_ID_NM9 34
#define PLV_NM9 KP_NUM PLV_ID_NM9
#define PLV_ID_NMA 35
#define PLV_NMA KP_NUM PLV_ID_NMA
#define PLV_ID_NMB 36
#define PLV_NMB KP_NUM PLV_ID_NMB
#define PLV_ID_NMC 37
#define PLV_NMC KP_NUM PLV_ID_NMC
#define PLV_ID_X1 38
#define PLV_X1 X PLV_ID_X1
#define PLV_ID_X2 39
#define PLV_X2 X PLV_ID_X2
#define PLV_ID_X3 40
#define PLV_X3 X PLV_ID_X3
#define PLV_ID_X4 41
#define PLV_X4 X PLV_ID_X4
#define PLV_ID_X5 42
#define PLV_X5 X PLV_ID_X5
#define PLV_ID_X6 43
#define PLV_X6 X PLV_ID_X6
#define PLV_ID_X7 44
#define PLV_X7 X PLV_ID_X7
#define PLV_ID_X8 45
#define PLV_X8 X PLV_ID_X8
#define PLV_ID_X9 46
#define PLV_X9 X PLV_ID_X9
#define PLV_ID_X10 47
#define PLV_X10 X PLV_ID_X10
#define PLV_ID_X11 48
#define PLV_X11 X PLV_ID_X11
#define PLV_ID_X12 49
#define PLV_X12 X PLV_ID_X12
#define PLV_ID_X13 50
#define PLV_X13 X PLV_ID_X13
#define PLV_ID_X14 51
#define PLV_X14 X PLV_ID_X14
#define PLV_ID_X15 52
#define PLV_X15 X PLV_ID_X15
#define PLV_ID_X16 53
#define PLV_X16 X PLV_ID_X16
#define PLV_ID_X17 54
#define PLV_X17 X PLV_ID_X17
#define PLV_ID_X18 55
#define PLV_X18 X PLV_ID_X18
#define PLV_ID_X19 56
#define PLV_X19 X PLV_ID_X19
#define PLV_ID_X20 57
#define PLV_X20 X PLV_ID_X20
#define PLV_ID_X21 58
#define PLV_X21 X PLV_ID_X21
#define PLV_ID_X22 59
#define PLV_X22 X PLV_ID_X22
#define PLV_ID_X23 60
#define PLV_X23 X PLV_ID_X23
#define PLV_ID_X24 61
#define PLV_X24 X PLV_ID_X24
#define PLV_ID_X25 62
#define PLV_X25 X PLV_ID_X25
#define PLV_ID_X26 63
#define PLV_X26 X PLV_ID_X26
