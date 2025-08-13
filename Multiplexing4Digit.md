## Multiplexing with 4-Digit 7-Segment Display

When working with multiple 7-segment displays (e.g., a 4-digit display), the microcontroller typically uses a technique called **multiplexing** to manage the display of each digit. Multiplexing allows you to control several digits with fewer pins by switching between the digits rapidly in a way that makes it appear as though all digits are displayed simultaneously.

```
    4        3        2        1
  -----    -----    -----    -----
 |     |  |     |  |     |  |     |
  -----    -----    -----    -----
 |     |  |     |  |     |  |     |
  -----    -----    -----    -----
```

### How Multiplexing Works:
In multiplexing, the microcontroller switches between digits one by one, activating only one digit at a time while keeping the others turned off. Each digit is displayed for a short period, and the cycle repeats for the next digit. The human eye perceives this rapid switching as continuous display of all digits.

- **Each digit** of the 7-segment display has its own common pin (e.g., the common cathode or common anode), and these common pins are controlled to switch between digits.
- **For example**, for a 4-digit display, you have four common pins, each connected to one of the 7-segment displays. The segments of the display are connected to GPIO pins of the microcontroller, and only one digit is activated at a time.

#### How Digits are Displayed:
1. The microcontroller lights up the first digit (e.g., the first 7-segment display).
2. The corresponding segments are activated to show the number.
3. The microcontroller turns off the first digit and turns on the second digit.
4. The same process repeats for the third and fourth digits.
5. The cycle continues at a fast enough rate that it seems like all digits are being displayed at once.

This process is done so quickly (at a high refresh rate) that the human eye perceives a smooth, continuous display of all four digits.

### Refresh Rate for Multiplexing:
To avoid flickering or noticeable gaps in the display, the microcontroller needs to switch between digits at a rate that is fast enough for the human eye to not notice the switching. The general rule of thumb is to refresh the display **at least 50 Hz**, which means the display should be updated 50 times per second. 

- For **4 digits**, this means that each digit should be displayed for approximately 1/4th of the total refresh cycle.
- The **total refresh rate** for all four digits is typically set at **50 Hz** or higher. This implies that each digit should be refreshed approximately every **5 ms** (milliseconds).

Thus, for a 50 Hz refresh rate:
- Each digit should be displayed for around **5 ms** before switching to the next digit.

If you want to achieve a smoother display with no visible flickering, it's ideal to aim for a refresh rate of **100 Hz or higher**. This means each digit would be refreshed every **2.5 ms**.

#### Example Calculation:
- If you're targeting a **refresh rate of 100 Hz**, the total time to refresh all four digits would be 10 ms (since 1 / 100 Hz = 10 ms).
- For each digit to be displayed in this 10 ms cycle, each digit should be refreshed for approximately **2.5 ms** (since 10 ms ÷ 4 digits = 2.5 ms per digit).

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
