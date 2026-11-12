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

/* ZMK Studio draws the first parameter on the key as a keyboard key label and
 * offers the second as a list of Plover HID keys by name.
 */
#define PLV_KEY(_value, _name) \
    { .display_name = _name, .value = _value, .type = BEHAVIOR_PARAMETER_VALUE_TYPE_VALUE }

static const struct behavior_parameter_value_metadata plover_hid_keys[] = {
    PLV_KEY(PLV_ID_SL, "S- 1"),
    PLV_KEY(PLV_ID_TL, "T-"),
    PLV_KEY(PLV_ID_KL, "K-"),
    PLV_KEY(PLV_ID_PL, "P-"),
    PLV_KEY(PLV_ID_WL, "W-"),
    PLV_KEY(PLV_ID_HL, "H-"),
    PLV_KEY(PLV_ID_RL, "R-"),
    PLV_KEY(PLV_ID_A, "A"),
    PLV_KEY(PLV_ID_O, "O"),
    PLV_KEY(PLV_ID_ST, "* 1"),
    PLV_KEY(PLV_ID_E, "E"),
    PLV_KEY(PLV_ID_U, "U"),
    PLV_KEY(PLV_ID_FR, "-F"),
    PLV_KEY(PLV_ID_RR, "-R"),
    PLV_KEY(PLV_ID_PR, "-P"),
    PLV_KEY(PLV_ID_BR, "-B"),
    PLV_KEY(PLV_ID_LR, "-L"),
    PLV_KEY(PLV_ID_GR, "-G"),
    PLV_KEY(PLV_ID_TR, "-T"),
    PLV_KEY(PLV_ID_SR, "-S"),
    PLV_KEY(PLV_ID_DR, "-D"),
    PLV_KEY(PLV_ID_ZR, "-Z"),
    PLV_KEY(PLV_ID_NM, "# 1"),
    PLV_KEY(PLV_ID_SL2, "S- 2"),
    PLV_KEY(PLV_ID_ST2, "* 2"),
    PLV_KEY(PLV_ID_ST3, "* 3"),
    PLV_KEY(PLV_ID_ST4, "* 4"),
    PLV_KEY(PLV_ID_NM2, "# 2"),
    PLV_KEY(PLV_ID_NM3, "# 3"),
    PLV_KEY(PLV_ID_NM4, "# 4"),
    PLV_KEY(PLV_ID_NM5, "# 5"),
    PLV_KEY(PLV_ID_NM6, "# 6"),
    PLV_KEY(PLV_ID_NM7, "# 7"),
    PLV_KEY(PLV_ID_NM8, "# 8"),
    PLV_KEY(PLV_ID_NM9, "# 9"),
    PLV_KEY(PLV_ID_NMA, "# 10"),
    PLV_KEY(PLV_ID_NMB, "# 11"),
    PLV_KEY(PLV_ID_NMC, "# 12"),
    PLV_KEY(PLV_ID_X1, "X1"),
    PLV_KEY(PLV_ID_X2, "X2"),
    PLV_KEY(PLV_ID_X3, "X3"),
    PLV_KEY(PLV_ID_X4, "X4"),
    PLV_KEY(PLV_ID_X5, "X5"),
    PLV_KEY(PLV_ID_X6, "X6"),
    PLV_KEY(PLV_ID_X7, "X7"),
    PLV_KEY(PLV_ID_X8, "X8"),
    PLV_KEY(PLV_ID_X9, "X9"),
    PLV_KEY(PLV_ID_X10, "X10"),
    PLV_KEY(PLV_ID_X11, "X11"),
    PLV_KEY(PLV_ID_X12, "X12"),
    PLV_KEY(PLV_ID_X13, "X13"),
    PLV_KEY(PLV_ID_X14, "X14"),
    PLV_KEY(PLV_ID_X15, "X15"),
    PLV_KEY(PLV_ID_X16, "X16"),
    PLV_KEY(PLV_ID_X17, "X17"),
    PLV_KEY(PLV_ID_X18, "X18"),
    PLV_KEY(PLV_ID_X19, "X19"),
    PLV_KEY(PLV_ID_X20, "X20"),
    PLV_KEY(PLV_ID_X21, "X21"),
    PLV_KEY(PLV_ID_X22, "X22"),
    PLV_KEY(PLV_ID_X23, "X23"),
    PLV_KEY(PLV_ID_X24, "X24"),
    PLV_KEY(PLV_ID_X25, "X25"),
    PLV_KEY(PLV_ID_X26, "X26"),
};

static const struct behavior_parameter_value_metadata plover_hid_label[] = {
    {.display_name = "Label", .type = BEHAVIOR_PARAMETER_VALUE_TYPE_HID_USAGE},
};

static const struct behavior_parameter_metadata_set plover_hid_key_set = {
    .param1_values = plover_hid_label,
    .param1_values_len = ARRAY_SIZE(plover_hid_label),
    .param2_values = plover_hid_keys,
    .param2_values_len = ARRAY_SIZE(plover_hid_keys),
};

static const struct behavior_parameter_metadata plover_hid_metadata = {
    .sets_len = 1,
    .sets = &plover_hid_key_set,
};

#endif /* IS_ENABLED(CONFIG_ZMK_BEHAVIOR_METADATA) */

static int behavior_plover_hid_init(const struct device *dev) { return 0; }

static int on_keymap_binding_pressed(struct zmk_behavior_binding *binding,
                                     struct zmk_behavior_binding_event event) {
    uint32_t key_index = binding->param2;
    LOG_DBG("position %d Plover HID key 0x%02X pressed", event.position, key_index);
    zmk_hid_plover_hid_set((uint8_t)key_index, true);
    zmk_endpoints_send_plover_hid_report_alt();
    return ZMK_BEHAVIOR_OPAQUE;
}

static int on_keymap_binding_released(struct zmk_behavior_binding *binding,
                                      struct zmk_behavior_binding_event event) {
    uint32_t key_index = binding->param2;
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
