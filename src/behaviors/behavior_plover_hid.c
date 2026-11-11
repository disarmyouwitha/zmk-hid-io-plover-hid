/*
 * Copyright (c) 2024 The ZMK Contributors
 *
 * SPDX-License-Identifier: MIT
 */

#define DT_DRV_COMPAT zmk_behavior_plover_hid

#include <zephyr/device.h>
#include <drivers/behavior.h>
#include <zephyr/logging/log.h>

#include <zmk/behavior.h>
#include <zmk/hid.h>

#include <zmk/hid-io/hid_plover_hid.h>
#include <zmk/hid-io/endpoints.h>

#include <dt-bindings/zmk/hid-io/plover_hid.h>

LOG_MODULE_DECLARE(zmk, CONFIG_ZMK_LOG_LEVEL);

#if DT_HAS_COMPAT_STATUS_OKAY(DT_DRV_COMPAT)

#if IS_ENABLED(CONFIG_ZMK_BEHAVIOR_METADATA)

/* Lets ZMK Studio offer each Plover HID key by name when assigning this behavior. */
#define PLV_KEY(_value, _name)                                                                         { .display_name = _name, .value = _value, .type = BEHAVIOR_PARAMETER_VALUE_TYPE_VALUE }

static const struct behavior_parameter_value_metadata plover_hid_keys[] = {
    PLV_KEY(PLV_SL, "S- 1"),
    PLV_KEY(PLV_SL2, "S- 2"),
    PLV_KEY(PLV_TL, "T-"),
    PLV_KEY(PLV_KL, "K-"),
    PLV_KEY(PLV_PL, "P-"),
    PLV_KEY(PLV_WL, "W-"),
    PLV_KEY(PLV_HL, "H-"),
    PLV_KEY(PLV_RL, "R-"),
    PLV_KEY(PLV_A, "A"),
    PLV_KEY(PLV_O, "O"),
    PLV_KEY(PLV_ST, "* 1"),
    PLV_KEY(PLV_ST2, "* 2"),
    PLV_KEY(PLV_ST3, "* 3"),
    PLV_KEY(PLV_ST4, "* 4"),
    PLV_KEY(PLV_E, "E"),
    PLV_KEY(PLV_U, "U"),
    PLV_KEY(PLV_FR, "-F"),
    PLV_KEY(PLV_RR, "-R"),
    PLV_KEY(PLV_PR, "-P"),
    PLV_KEY(PLV_BR, "-B"),
    PLV_KEY(PLV_LR, "-L"),
    PLV_KEY(PLV_GR, "-G"),
    PLV_KEY(PLV_TR, "-T"),
    PLV_KEY(PLV_SR, "-S"),
    PLV_KEY(PLV_DR, "-D"),
    PLV_KEY(PLV_ZR, "-Z"),
    PLV_KEY(PLV_NM, "# 1"),
    PLV_KEY(PLV_NM2, "# 2"),
    PLV_KEY(PLV_NM3, "# 3"),
    PLV_KEY(PLV_NM4, "# 4"),
    PLV_KEY(PLV_NM5, "# 5"),
    PLV_KEY(PLV_NM6, "# 6"),
    PLV_KEY(PLV_NM7, "# 7"),
    PLV_KEY(PLV_NM8, "# 8"),
    PLV_KEY(PLV_NM9, "# 9"),
    PLV_KEY(PLV_NMA, "# 10"),
    PLV_KEY(PLV_NMB, "# 11"),
    PLV_KEY(PLV_NMC, "# 12"),
    PLV_KEY(PLV_X1, "X1"),
    PLV_KEY(PLV_X2, "X2"),
    PLV_KEY(PLV_X3, "X3"),
    PLV_KEY(PLV_X4, "X4"),
    PLV_KEY(PLV_X5, "X5"),
    PLV_KEY(PLV_X6, "X6"),
    PLV_KEY(PLV_X7, "X7"),
    PLV_KEY(PLV_X8, "X8"),
    PLV_KEY(PLV_X9, "X9"),
    PLV_KEY(PLV_X10, "X10"),
    PLV_KEY(PLV_X11, "X11"),
    PLV_KEY(PLV_X12, "X12"),
    PLV_KEY(PLV_X13, "X13"),
    PLV_KEY(PLV_X14, "X14"),
    PLV_KEY(PLV_X15, "X15"),
    PLV_KEY(PLV_X16, "X16"),
    PLV_KEY(PLV_X17, "X17"),
    PLV_KEY(PLV_X18, "X18"),
    PLV_KEY(PLV_X19, "X19"),
    PLV_KEY(PLV_X20, "X20"),
    PLV_KEY(PLV_X21, "X21"),
    PLV_KEY(PLV_X22, "X22"),
    PLV_KEY(PLV_X23, "X23"),
    PLV_KEY(PLV_X24, "X24"),
    PLV_KEY(PLV_X25, "X25"),
    PLV_KEY(PLV_X26, "X26"),
};

static const struct behavior_parameter_metadata_set plover_hid_key_set = {
    .param1_values = plover_hid_keys,
    .param1_values_len = ARRAY_SIZE(plover_hid_keys),
};

static const struct behavior_parameter_metadata plover_hid_metadata = {
    .sets_len = 1,
    .sets = &plover_hid_key_set,
};

#endif /* IS_ENABLED(CONFIG_ZMK_BEHAVIOR_METADATA) */

static int behavior_plover_hid_init(const struct device *dev) { return 0; }

static int on_keymap_binding_pressed(struct zmk_behavior_binding *binding,
                                     struct zmk_behavior_binding_event event) {
    uint32_t key_index = binding->param1;
    LOG_DBG("position %d Plover HID key 0x%02X pressed", event.position, key_index);
    zmk_hid_plover_hid_set((uint8_t)key_index, true);
    zmk_endpoints_send_plover_hid_report_alt();
    return ZMK_BEHAVIOR_OPAQUE;
}

static int on_keymap_binding_released(struct zmk_behavior_binding *binding,
                                      struct zmk_behavior_binding_event event) {
    uint32_t key_index = binding->param1;
    LOG_DBG("position %d Plover HID key 0x%02X released", event.position, key_index);
    zmk_hid_plover_hid_set((uint8_t)key_index, false);
    zmk_endpoints_send_plover_hid_report_alt();
    return ZMK_BEHAVIOR_OPAQUE;
}

static const struct behavior_driver_api behavior_plover_hid_driver_api = {
    .binding_pressed = on_keymap_binding_pressed,
    .binding_released = on_keymap_binding_released,
#if IS_ENABLED(CONFIG_ZMK_BEHAVIOR_METADATA)
    .parameter_metadata = &plover_hid_metadata,
#endif /* IS_ENABLED(CONFIG_ZMK_BEHAVIOR_METADATA) */
};

#define PLV_INST(n)                                                        \
    BEHAVIOR_DT_INST_DEFINE(n, behavior_plover_hid_init, NULL,            \
                            NULL, NULL, POST_KERNEL,                       \
                            CONFIG_KERNEL_INIT_PRIORITY_DEFAULT,           \
                            &behavior_plover_hid_driver_api);

DT_INST_FOREACH_STATUS_OKAY(PLV_INST)

#endif /* DT_HAS_COMPAT_STATUS_OKAY(DT_DRV_COMPAT) */
