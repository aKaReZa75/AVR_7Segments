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

 #include "Seg7.h"

 /**
  * @brief Segment-to-segment mapping for 0-9 using Common Cathode configuration.
  * 
  * This array holds the segment bit pattern for each digit (0-9) for a 7-segment display.
  */
 const uint8_t Segments_Data[16] = 
 {
  0x3F, /**< 0 */
  0x06, /**< 1 */
  0x5B, /**< 2 */
  0x4F, /**< 3 */
  0x66, /**< 4 */
  0x6D, /**< 5 */
  0x7D, /**< 6 */
  0x07, /**< 7 */
  0x7F, /**< 8 */
  0x6F, /**< 9 */
  0x77, /**< A */
  0x7C, /**< b */
  0x39, /**< C */
  0x5E, /**< d */
  0x79, /**< E */
  0x71  /**< F */
 };
 
 /** 
  * @brief Array to store the individual digits for the 4-digit display.
  * 
  * This array holds the values of the individual digits (thousands, hundreds, tens, ones).
  */
 uint8_t Segment[4] = {0, 0, 0, 0};
 

 /**
  * @brief Initializes the 7-segment display.
  * 
  * This function configures the control and data direction registers for all segments (A-G) 
  * and digits (1-4) of the 7-segment display.
  * It sets each pin as an output to allow control of the display.
  */
 void Seg7_init(void)
 {
  /* Configure all the control and segment pins as outputs */
  GPIO_Config_OUTPUT(__7Seg_A_Config, __7Seg_A_Pin); 
  GPIO_Config_OUTPUT(__7Seg_B_Config, __7Seg_B_Pin); 
  GPIO_Config_OUTPUT(__7Seg_C_Config, __7Seg_C_Pin); 
  GPIO_Config_OUTPUT(__7Seg_D_Config, __7Seg_D_Pin); 
  GPIO_Config_OUTPUT(__7Seg_E_Config, __7Seg_E_Pin); 
  GPIO_Config_OUTPUT(__7Seg_F_Config, __7Seg_F_Pin); 
  GPIO_Config_OUTPUT(__7Seg_G_Config, __7Seg_G_Pin); 
  GPIO_Config_OUTPUT(__7Seg_DP_Config, __7Seg_DP_Pin); 
  GPIO_Config_OUTPUT(__7Seg_Digit1_Config, __7Seg_Digit1_Pin);
  GPIO_Config_OUTPUT(__7Seg_Digit2_Config, __7Seg_Digit2_Pin);
  GPIO_Config_OUTPUT(__7Seg_Digit3_Config, __7Seg_Digit3_Pin);
  GPIO_Config_OUTPUT(__7Seg_Digit4_Config, __7Seg_Digit4_Pin);

  /* Set control pins for digits as outputs */
  GPIO_Config_OUTPUT(__7Seg_Digit1_Control, __7Seg_Digit1_Pin); 
  GPIO_Config_OUTPUT(__7Seg_Digit2_Control, __7Seg_Digit2_Pin); 
  GPIO_Config_OUTPUT(__7Seg_Digit3_Control, __7Seg_Digit3_Pin); 
  GPIO_Config_OUTPUT(__7Seg_Digit4_Control, __7Seg_Digit4_Pin); 
 }
 
 /**
  * @brief Displays a 4-digit number on the 7-segment display using multiplexing.
  * 
  * This function displays a number on the 7-segment display by sequentially activating 
  * each digit and lighting up the corresponding segments. The function uses multiplexing 
  * to display all 4 digits in quick succession, creating the illusion that they are 
  * all being shown at once.
  * 
  * @param _7SegValue The 4-digit value (0-9999) to display on the 7-segment display.
  */
 void Seg7_Puti(uint16_t _7SegValue) 
 {
  static uint8_t _Digit = 0; /**< Variable to determine which digit to activate */

  /* Extract digits (thousands to ones) from the 7-segment value */
  Segment[3] = (_7SegValue % 10); /**< thousands (Digit4) */
  _7SegValue /= 10;
  Segment[2] = (_7SegValue % 10); /**< hundreds (Digit3) */
  _7SegValue /= 10;
  Segment[1] = (_7SegValue % 10); /**< tens (Digit2) */
  _7SegValue /= 10;
  Segment[0] = (_7SegValue % 10); /**< ones (Digit1) */

  /* Update the segments based on the current digit to display */
  bitChange(__7Seg_A_Control, __7Seg_A_Pin, bitCheck(Segments_Data[Segment[_Digit]], 0));
  bitChange(__7Seg_B_Control, __7Seg_B_Pin, bitCheck(Segments_Data[Segment[_Digit]], 1));
  bitChange(__7Seg_C_Control, __7Seg_C_Pin, bitCheck(Segments_Data[Segment[_Digit]], 2));
  bitChange(__7Seg_D_Control, __7Seg_D_Pin, bitCheck(Segments_Data[Segment[_Digit]], 3));
  bitChange(__7Seg_E_Control, __7Seg_E_Pin, bitCheck(Segments_Data[Segment[_Digit]], 4));
  bitChange(__7Seg_F_Control, __7Seg_F_Pin, bitCheck(Segments_Data[Segment[_Digit]], 5));
  bitChange(__7Seg_G_Control, __7Seg_G_Pin, bitCheck(Segments_Data[Segment[_Digit]], 6));

  /* Activate the corresponding digit */
  bitChange(__7Seg_Digit1_Control, __7Seg_Digit1_Pin, bitCheck((1<<_Digit), 0));
  bitChange(__7Seg_Digit2_Control, __7Seg_Digit2_Pin, bitCheck((1<<_Digit), 1));
  bitChange(__7Seg_Digit3_Control, __7Seg_Digit3_Pin, bitCheck((1<<_Digit), 2));
  bitChange(__7Seg_Digit4_Control, __7Seg_Digit4_Pin, bitCheck((1<<_Digit), 3));

  /* Increment the _Digit and reset if necessary */
  _Digit++;
  if (_Digit == 4) 
  {
    _Digit = 0;
  };
 };
 