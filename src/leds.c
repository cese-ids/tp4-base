/************************************************************************************************
Copyright (c) 2023, Esteban Volentini <evolentini@herrera.unt.edu.ar>

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
associated documentation files (the "Software"), to deal in the Software without restriction,
including without limitation the rights to use, copy, modify, merge, publish, distribute,
sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial
portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT
NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES
OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

SPDX-License-Identifier: MIT
*************************************************************************************************/

/** @file leds.c
 ** @brief Implementación de la biblioteca para manejo de leds
 **/

/* === Headers files inclusions =============================================================== */

#include "leds.h"

/* === Macros definitions ====================================================================== */

//! Constante con el bit menos significativo en alto
#define BIT_HIGH 1

//! Constante con la diferencia entre el numero de led y el numero de bit correspondiente
#define LED_OFFSET 1

//! Constante para apagar todos los leds
#define ALL_LED_OFF 0x00

/* === Private data type declarations ========================================================== */

/* === Private variable declarations =========================================================== */

//! Variable para almacenar el puntero al puerto de los leds
static uint16_t * puntero;

/* === Private function declarations =========================================================== */

/**
 * @brief Función para convertir el numero de led en una masca de bits
 *
 * @param led Numero de led que se desea manipular (del 1 al 16)
 * @return uint16_t Mascara con el bit correspondiente al led en 1 y el resto en 0
 */
static uint16_t led_to_mask(int led);

/* === Public variable definitions ============================================================= */

/* === Private variable definitions ============================================================ */

/* === Private function implementation ========================================================= */

static uint16_t led_to_mask(int led) {
    return (BIT_HIGH << (led - LED_OFFSET));
}

/* === Public function implementation ========================================================== */

void leds_init(uint16_t * puerto) {
    puntero = puerto;
    *puntero = ALL_LED_OFF;
}

void leds_turn_on(int led) {
    *puntero |= led_to_mask(led);
}

void leds_turn_off(int led) {
    *puntero &= ~led_to_mask(led);
}

/* === End of documentation ==================================================================== */
