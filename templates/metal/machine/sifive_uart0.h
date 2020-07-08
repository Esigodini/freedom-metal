/* Copyright 2020 SiFive, Inc */
/* SPDX-License-Identifier: Apache-2.0 */

#ifndef METAL__PLATFORM__SIFIVE_UART0_H
#define METAL__PLATFORM__SIFIVE_UART0_H

{% for uart in uarts %}
#define METAL_SIFIVE_UART0_{{ loop.index0 }}_BASE_ADDR {{ '0x%x' % uart.regs_by_name["control"] }}
{% endfor %}

#define METAL_SIFIVE_UART0
#define METAL_SIFIVE_UART0_TXDATA 0UL
#define METAL_SIFIVE_UART0_RXDATA 4UL
#define METAL_SIFIVE_UART0_TXCTRL 8UL
#define METAL_SIFIVE_UART0_RXCTRL 12UL
#define METAL_SIFIVE_UART0_IE 16UL
#define METAL_SIFIVE_UART0_IP 20UL
#define METAL_SIFIVE_UART0_DIV 24UL

#endif