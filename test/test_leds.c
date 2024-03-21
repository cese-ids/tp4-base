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

/** @file test_leds.c
 ** @brief Pruebas unitarias de la biblioteca para manejo de leds
 **/

//! @todo Prender todos los leds que estan apagados en una sola operación
//! @todo Apagar todos los leds que ya estan prendidos
//! @todo Prender leds que ya esten prendidos de antes
//! @todo Apagar leds que ya esten apagados
//! @todo Comprobar valores prohibidos
//! @todo Comprobar los valores de limite

/* === Headers files inclusions =============================================================== */

#include "leds.h"
#include "unity.h"

/* === Macros definitions ====================================================================== */

static const int LED = 3;

/* === Private data type declarations ========================================================== */

/* === Private variable declarations =========================================================== */

static uint16_t leds_virtuales;

/* === Private function declarations =========================================================== */

/* === Public variable definitions ============================================================= */

/* === Private variable definitions ============================================================ */

/* === Private function implementation ========================================================= */

/* === Public function implementation ========================================================== */

void setUp(void) {
    leds_init(&leds_virtuales);
}

//! @test Al iniciar el controlador todos los leds deben quedar apagados.
void test_todos_los_leds_inician_apagados(void) {
    uint16_t leds_virtuales = 0xFF;
    leds_init(&leds_virtuales);
    TEST_ASSERT_EQUAL_UINT16(0x00, leds_virtuales);
}

/**
 * @test Con todos los leds apagados prender el led 3 y verificar que
 * efectivamente el bit 2 se pone en 1 y el resto de bit permanece en 0
 */
void test_prender_un_led(void) {
    leds_turn_on(LED);

    // El bit 2 está en alto
    TEST_ASSERT_BIT_HIGH(LED - 1, leds_virtuales);
    // Todos los otros bits estan en bajo
    TEST_ASSERT_BITS_LOW(~(1 << (LED - 1)), leds_virtuales);
}

/**
 * @test Apagar un led prendido y ver que efectivamente se apaga
 * y que el resto no cambia su estado.
 */
void test_apagar_un_led(void) {
    leds_turn_on(LED);
    leds_turn_off(LED);

    // Todos los bits estan en bajo
    TEST_ASSERT_EQUAL_UINT16(0x00, leds_virtuales);
}

/**
 * @test Prender y apagar varios leds par comprobar el estado final de cada uno
 */
void test_prender_y_apagar_varios_leds(void) {
    leds_turn_on(5);
    leds_turn_on(7);
    leds_turn_off(5);

    // El bit 6 está en alto y el resto en bajo
    TEST_ASSERT_EQUAL_UINT16(1 << (7 - 1), leds_virtuales);
}
/* === End of documentation ==================================================================== */
