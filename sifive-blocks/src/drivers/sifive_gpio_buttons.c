/* Copyright (c) 2020 SiFive, Inc */
/* Copyright © 2020 Keith Packard */
/*
 * Licensed under the Apache License, Version 2.0 (the “License”); you
 * may not use this file except in compliance with the License. A copy
 * of this license can be found in the LICENSE.Apache2 file included
 * with this software. You may also obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an “AS IS” BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or
 * implied. See the License for the specific language governing
 * permissions and limitations under the License.
 */
/* SPDX-License-Identifier: Apache-2.0 */

#include <metal/platform.h>

#ifdef METAL_SIFIVE_GPIO_BUTTONS

#include <metal/button.h>
#include <metal/gpio.h>
#include <metal/private/metal_private_sifive_gpio_buttons.h>

bool sifive_gpio_buttons_is_pressed(struct metal_button button) {
    if (metal_button_is_none(button))
        return false;
    metal_gpio_enable_input(BUTTON_GPIO(button), BUTTON_GPIO_PIN(button));
    return metal_gpio_get_input_pin(BUTTON_GPIO(button),
                                    BUTTON_GPIO_PIN(button));
}

int sifive_gpio_buttons_enable_interrupt(struct metal_button button) {
    if (metal_button_is_none(button))
        return 0;
    metal_gpio_enable_input(BUTTON_GPIO(button), BUTTON_GPIO_PIN(button));
    return metal_gpio_config_interrupt(
        BUTTON_GPIO(button), BUTTON_GPIO_PIN(button), METAL_GPIO_INT_RISING);
}

int sifive_gpio_buttons_disable_interrupt(struct metal_button button) {
    if (metal_button_is_none(button))
        return 0;
    metal_gpio_enable_input(BUTTON_GPIO(button), BUTTON_GPIO_PIN(button));
    return metal_gpio_config_interrupt(
        BUTTON_GPIO(button), BUTTON_GPIO_PIN(button), METAL_GPIO_INT_DISABLE);
}

int sifive_gpio_buttons_clear_interrupt(struct metal_button button) {
    if (metal_button_is_none(button))
        return 0;
    return metal_gpio_clear_interrupt(
        BUTTON_GPIO(button), BUTTON_GPIO_PIN(button), METAL_GPIO_INT_RISING);
}

#endif

typedef int no_empty_translation_units;
