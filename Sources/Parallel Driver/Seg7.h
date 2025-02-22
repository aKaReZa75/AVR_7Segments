/**
 * @file     Seg7.c
 * @brief    7-segment display control library for AVR microcontrollers
 * @note     This file provides functionality to control a 4-digit 7-segment display 
 *           using multiplexing for AVR microcontrollers.
 * 
 * @author   Your Name
 * @github   Your GitHub Link
 * 
 * @note     For detailed explanations of this library, along with additional notes and examples of usage, 
 *           please visit the following repository:
 *           https://github.com/aKaReZa75/AVR_7Segments
 */
#ifndef _Seg7_H_ 
#define _Seg7_H_

#include "aKaReZa.h"

/** 
 * @brief Control and configuration macros for 7-segment display segments (A to G).
 * 
 * These macros define the control ports, configuration ports, and pins for each segment of the 7-segment display.
 */

/* Define control and configuration for segment A */
#define __7Seg_A_Control PORTC /**< Control port for segment A */
#define __7Seg_A_Config  DDRC /**< Data direction register for segment A */
#define __7Seg_A_Pin     0    /**< Pin number for segment A */

/* Define control and configuration for segment B */
#define __7Seg_B_Control PORTC /**< Control port for segment B */
#define __7Seg_B_Config  DDRC /**< Data direction register for segment B */
#define __7Seg_B_Pin     1    /**< Pin number for segment B */

/* Define control and configuration for segment C */
#define __7Seg_C_Control PORTC /**< Control port for segment C */
#define __7Seg_C_Config  DDRC /**< Data direction register for segment C */
#define __7Seg_C_Pin     2    /**< Pin number for segment C */

/* Define control and configuration for segment D */
#define __7Seg_D_Control PORTC /**< Control port for segment D */
#define __7Seg_D_Config  DDRC /**< Data direction register for segment D */
#define __7Seg_D_Pin     3    /**< Pin number for segment D */

/* Define control and configuration for segment E */
#define __7Seg_E_Control PORTD /**< Control port for segment E */
#define __7Seg_E_Config  DDRD /**< Data direction register for segment E */
#define __7Seg_E_Pin     0    /**< Pin number for segment E */

/* Define control and configuration for segment F */
#define __7Seg_F_Control PORTD /**< Control port for segment F */
#define __7Seg_F_Config  DDRD /**< Data direction register for segment F */
#define __7Seg_F_Pin     1    /**< Pin number for segment F */

/* Define control and configuration for segment G */
#define __7Seg_G_Control PORTD /**< Control port for segment G */
#define __7Seg_G_Config  DDRD /**< Data direction register for segment G */
#define __7Seg_G_Pin     4    /**< Pin number for segment G */

/* Define control and configuration for decimal point (DP) */
#define __7Seg_DP_Control PORTD /**< Control port for the decimal point (DP) */
#define __7Seg_DP_Config  DDRD /**< Data direction register for DP */
#define __7Seg_DP_Pin     7    /**< Pin number for the decimal point (DP) */

/* Define control and configuration for each digit */
#define __7Seg_Digit1_Control PORTB /**< Control port for Digit 1 */
#define __7Seg_Digit1_Config DDRB /**< Data direction register for Digit 1 */
#define __7Seg_Digit1_Pin 0 /**< Pin number for Digit 1 */

#define __7Seg_Digit2_Control PORTB /**< Control port for Digit 2 */
#define __7Seg_Digit2_Config DDRB /**< Data direction register for Digit 2 */
#define __7Seg_Digit2_Pin 1 /**< Pin number for Digit 2 */

#define __7Seg_Digit3_Control PORTB /**< Control port for Digit 3 */
#define __7Seg_Digit3_Config DDRB /**< Data direction register for Digit 3 */
#define __7Seg_Digit3_Pin 2 /**< Pin number for Digit 3 */

#define __7Seg_Digit4_Control PORTB /**< Control port for Digit 4 */
#define __7Seg_Digit4_Config DDRB /**< Data direction register for Digit 4 */
#define __7Seg_Digit4_Pin 4 /**< Pin number for Digit 4 */

/** 
 * @brief Initializes the 7-segment display.
 * 
 * This function configures the appropriate ports and pins for controlling the 7-segment display. 
 * It sets the direction for each pin (input/output) and initializes the display for use.
 */
void Seg7_init(void);

/** 
 * @brief Displays a number on the 7-segment display.
 * 
 * This function takes a 4-digit value (0-9999) and displays it on the 7-segment display using multiplexing.
 * It will handle sequentially displaying each digit with appropriate timing.
 *
 * @param _7SegValue The 4-digit number to be displayed on the 7-segment display.
 */
void Seg7_Puti(uint16_t _7SegValue);

#endif
