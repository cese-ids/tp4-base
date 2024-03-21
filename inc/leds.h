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

#ifndef LEDS_H
#define LEDS_H

/** @file leds.h
 ** @brief Definiciones de la biblioteca para manejo de leds
 **/

/* === Headers files inclusions ================================================================ */

#include <stdint.h>

/* === Cabecera C++ ============================================================================ */

#ifdef __cplusplus
extern "C" {
#endif

/* === Public macros definitions =============================================================== */

/* === Public data type declarations =========================================================== */

/* === Public variable declarations ============================================================ */

/* === Public function declarations ============================================================ */

/**
 * @brief Función principal del sistema, se ejecuta al iniciar el programa
 *
 * @return int Valor de retorno, cero si esta todo bien, negativo si hay un error
 */
int main(void);

/**
 * @brief Función para configurar la biblioteca
 *
 * @remark Esta función debe ser llamada antes que cualquier otra función de la biblioteca
 *
 * @param puerto
 */
void leds_init(uint16_t * puerto);

/**
 * @brief Función para prender un led individual
 *
 * @param led Numero de led a prender (del 1 al 16)
 */
void leds_turn_on(int led);

/**
 * @brief Función para apagar un led inividual
 *
 * @param led Numero de led a apagar (del 1 al 16)
 */
void leds_turn_off(int led);

/* === End of documentation ==================================================================== */

#ifdef __cplusplus
}
#endif

#endif /* MAIN_H */
