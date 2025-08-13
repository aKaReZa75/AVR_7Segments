## API Reference

The following API functions are designed to help with controlling 7-segment displays on the ATMEGA328 microcontroller.

> [!NOTE]  
> The library and all of its APIs provided below have been developed by myself.  
This library utilizes various macros defined in the `aKaReZa.h` header file, which are designed to simplify bitwise operations and register manipulations.    
Detailed descriptions of these macros can be found at the following link:  
> [https://github.com/aKaReZa75/AVR/blob/main/Macros.md](https://github.com/aKaReZa75/AVR/blob/main/Macros.md)  


### Flexible Pin Assignment
This library allows you to easily control 7-segment displays, and it is designed with flexibility in mind. Each segment of the 7-segment display (A through G) can be connected to any available pin of the ATMEGA328 microcontroller. This flexibility is crucial because it allows you to customize the pin connections based on your design needs, without being restricted by predefined hardware mappings.

To make pin configuration easier and more manageable, the `Seg7.h` header file defines a set of macros that allow the user to specify which microcontroller pins should be used for each segment and digit control. This means that each segment (A, B, C, D, E, F, G, and the DP) can be assigned to any GPIO pin of the ATMEGA328.

### Example Pin Configuration
In the `Seg7.h` header file, you'll find a set of macros that define the pin assignments for the 7-segment display. These macros are set to specific pins by default, but you can easily change them to any other pin on the microcontroller. For instance, the default configuration may look like this:

> [!NOTE]
These default pin assignments are based on the pin configuration for the 7-segment shield, as found in the [7Segment Shield](https://github.com/aKaReZa75/eBoard_7Segments) repository.

```c
#define _7Seg_A_Control PORTC
#define _7Seg_A_Config  DDRC
#define _7Seg_A_Pin     0

#define _7Seg_B_Control PORTC
#define _7Seg_B_Config  DDRC
#define _7Seg_B_Pin     1

#define _7Seg_C_Control PORTC
#define _7Seg_C_Config  DDRC
#define _7Seg_C_Pin     2

#define _7Seg_D_Control PORTC
#define _7Seg_D_Config  DDRC
#define _7Seg_D_Pin     3

#define _7Seg_E_Control PORTD
#define _7Seg_E_Config  DDRD
#define _7Seg_E_Pin     0

#define _7Seg_F_Control PORTD
#define _7Seg_F_Config  DDRD
#define _7Seg_F_Pin     1

#define _7Seg_G_Control PORTD
#define _7Seg_G_Config  DDRD
#define _7Seg_G_Pin     4

#define _7Seg_DP_Control PORTD
#define _7Seg_DP_Config DDRD
#define _7Seg_DP_Pin    7

#define _7Seg_Digit1_Control PORTB
#define _7Seg_Digit1_Config DDRB
#define _7Seg_Digit1_Pin   0

#define _7Seg_Digit2_Control PORTB
#define _7Seg_Digit2_Config DDRB
#define _7Seg_Digit2_Pin   1

#define _7Seg_Digit3_Control PORTB
#define _7Seg_Digit3_Config DDRB
#define _7Seg_Digit3_Pin   2

#define _7Seg_Digit4_Control PORTB
#define _7Seg_Digit4_Config DDRB
#define _7Seg_Digit4_Pin   4
```

#### How It Works
- The macros defined in the `Seg7.h` file specify which microcontroller pins are used for each segment and each digit of the 7-segment display.
- For example:
  - `_7Seg_A_Control` and `_7Seg_A_Pin` correspond to the control port (PORTC) and pin (pin 0) for segment A.
  - Similarly, `_7Seg_B_Control` and `_7Seg_B_Pin` define the port and pin for segment B, and so on for the remaining segments and digits.
  
- By using these macros, you can configure each segment and each digit of the display to any port and pin you choose, just by modifying the macro definitions. This flexibility allows you to adapt the code to your specific hardware setup, making it ideal for a wide range of projects.

For example, if you want to change the pin for segment A to pin 5 of PORTB, you can modify the macro like this:

```c
#define _7Seg_A_Control PORTB
#define _7Seg_A_Config  DDRB
#define _7Seg_A_Pin     5
```

This allows you to control which pins are connected to each segment, ensuring that you have full control over your display setup.

### **Initialization**
```c
void Seg7_init(void);
```
* Initializes the 7-segment display configuration.
* This function sets the appropriate pin directions for controlling the segments and digits of the 7-segment display.
* It configures all the necessary pins as output.
  
**Default Configuration**

| **Segment/Digit**         | **Control Port & Pin**   |
|---------------------------|--------------------------|
| **Type of 7-Segment**      | Common Cathode           |
| **Number of Digits**       | 4                        |
| **Segment A**              | PORTC, Pin 0             |
| **Segment B**              | PORTC, Pin 1             |
| **Segment C**              | PORTC, Pin 2             |
| **Segment D**              | PORTC, Pin 3             |
| **Segment E**              | PORTD, Pin 0             |
| **Segment F**              | PORTD, Pin 1             |
| **Segment G**              | PORTD, Pin 4             |
| **Decimal Point (DP)**     | PORTD, Pin 7             |
| **Digit 1 (Thousands)**    | PORTB, Pin 0             |
| **Digit 2 (Hundreds)**     | PORTB, Pin 1             |
| **Digit 3 (Tens)**         | PORTB, Pin 2             |
| **Digit 4 (Ones)**         | PORTB, Pin 4             |  
  
**Example:**
```c
#include "aKaReZa.h"
#include "Seg7.h"

int main(void) 
{
    Seg7_init(); /**< Initialize the 7-segment display */
    while(1)
    {
        /* Your code here to display values */
    }
}
```

### **Display Number**
```c
void Seg7_Puti(uint16_t _7SegValue);
```
* Displays a 4-digit number on the multiplexed 7-segment display.
* This function uses multiplexing to display the digits sequentially with a short delay between each to simulate continuous display of the 4-digit value.
* It will handle turning on the correct segments for each digit.

> [!IMPORTANT]
Currently, only **positive integers** between **0 and 9999** can be displayed.   
Additionally, only a **4-digit 7-segment display** is supported at the moment. 


**Example:**
```c
#include "aKaReZa.h"
#include "Seg7.h"

int main(void) 
{
    Seg7_init(); /**< Initialize the 7-segment display */
    while(1)
    {
        Seg7_Puti(1234); /**< Display the number 1234 */
    }
}
```

> [!CAUTION]
For continuous display, the `Seg7_Puti` function needs to be executed continuously.    
It is recommended to use a **timer** to trigger the execution of the function at a fixed interval.   
This will prevent delays in the main program loop and ensure smoother performance by automating the multiplexing refresh.

## Summary

Here’s a quick summary of the available functions:

| Function Name        | Description                                      |
|----------------------|--------------------------------------------------|
| `Seg7_init()`         | Initializes the 7-segment display configuration. |
| `Seg7_Puti(uint16_t)` | Displays a 4-digit value on the multiplexed 7-segment display. |

## Complete Example

The following example demonstrates how to initialize the 7-segment display, display a 4-digit number using multiplexing, and use a timer interrupt to update the display continuously.

```c
#include "aKaReZa.h"
#include "Seg7.h"

/* Timer0 Overflow Interrupt Service Routine (ISR) */
ISR(TIMER0_OVF_vect)
{
    Seg7_Puti(1234);  /* Update the 7-segment display */
};

int main(void) 
{
    Seg7_init(); /**< Initialize the 7-segment display */
    
    Timer0_Init(Initialize); /**< Initialize Timer0 for periodic updates */
    
    globalInt_Enable(); /**< Enable global interrupts */
    
    while(1)
    {
        /* Main loop can be used for other tasks, the display will update automatically via Timer0 interrupt */
    };
};
```

### Explanation:

In this example, the 7-Segments will be updated continuously at the specified interval (1ms in this case) due to the timer interrupt.

## Important Notes

- **Multiplexing**: The 7-segment display operates using multiplexing, meaning each digit is displayed sequentially for a short period. This creates the illusion that all digits are visible at once. Ensure that the refresh rate is set appropriately to avoid flickering.
- **Power Consumption**: Be cautious about power consumption when driving multiple 7-segment displays, as this can draw significant current.
- **Pin Configuration**: Make sure the correct pins are defined in the header file. If you modify the microcontroller's pin configuration or use different segments, update the pin assignments accordingly.
- **Delay Timing**: If the delay between digit switching is too short, the display may become unreadable. If it’s too long, the display might appear sluggish.
- **Initialization**: Don’t forget to initialize the 7-segment display by calling `Seg7_init()`.
- **Wiring Issues**: Ensure that the segments and common cathodes/anodes are wired correctly.
- **Low Refresh Rate**: A refresh rate below 50 Hz may cause visible flickering, making the display hard to read.

# 🌟 Support Me
If you found this repository useful:
- Subscribe to my [YouTube Channel](https://www.youtube.com/@aKaReZa75).
- Share this repository with others.
- Give this repository and my other repositories a star.
- Follow my [GitHub account](https://github.com/aKaReZa75).

# ✉️ Contact Me
Feel free to reach out to me through any of the following platforms:
- 📧 [Email: aKaReZa75@gmail.com](mailto:aKaReZa75@gmail.com)
- 🎥 [YouTube: @aKaReZa75](https://www.youtube.com/@aKaReZa75)
- 💼 [LinkedIn: @akareza75](https://www.linkedin.com/in/akareza75)
