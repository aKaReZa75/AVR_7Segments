## How a 7-Segment Display Works
A 7-segment display has 7 individual LEDs arranged in the form of a figure-eight. The following is a representation of the segments:

```
    A
  -----
F|     |B
  -----
G|     |C
  -----
    D
```

Each segment can be turned on or off, and by doing so in different combinations, you can display numbers or letters. For example, to display the number '1', you would turn on segments B and C, and leave the rest off. To display the number '8', all segments (A-G) would be turned on.

### Common Cathode vs. Common Anode

There are two types of 7-segment displays: **common cathode** and **common anode**.

- **Common Cathode**: In a common cathode display, all the cathodes (negative side) of the individual segments are connected together and are typically connected to ground (GND). Each segment is controlled by applying a HIGH signal to the corresponding anode (positive side). The segments light up when a HIGH signal is applied.

- **Common Anode**: In a common anode display, all the anodes (positive side) of the individual segments are connected together and are typically connected to the VCC (positive voltage). Each segment is controlled by applying a LOW signal to the corresponding cathode (negative side). The segments light up when a LOW signal is applied.

In both cases, each individual segment is represented by a pin, and by controlling these pins, you can display numbers. The only difference between common anode and common cathode displays is the polarity of the voltage applied to the segments.

#### Example of Segment Control for Common Cathode:
To display the number '3', the required segments are A, B, C, D, and G. In a common cathode configuration:
- Apply a HIGH signal to segments A, B, C, D, and G.
- The other segments (E, F) remain off.

#### Example of Segment Control for Common Anode:
To display the number '3', the required segments are A, B, C, D, and G. In a common anode configuration:
- Apply a LOW signal to segments A, B, C, D, and G.
- The other segments (E, F) remain off.

### 7-Segment Display Segment Control (Hexadecimal Format)

| Digit | A | B | C | D | E | F | G | Common Cathode | Common Anode |
|-------|---|---|---|---|---|---|---|----------------|--------------|
| 0     | 1 | 1 | 1 | 1 | 1 | 1 | 0 | **0x3F**       | **0xC0**     |
| 1     | 0 | 1 | 1 | 0 | 0 | 0 | 0 | **0x06**       | **0xF9**     |
| 2     | 1 | 1 | 0 | 1 | 1 | 0 | 1 | **0x5B**       | **0xA4**     |
| 3     | 1 | 1 | 1 | 1 | 0 | 0 | 1 | **0x4F**       | **0xB0**     |
| 4     | 0 | 1 | 1 | 0 | 0 | 1 | 1 | **0x66**       | **0x99**     |
| 5     | 1 | 0 | 1 | 1 | 0 | 1 | 1 | **0x6D**       | **0x92**     |
| 6     | 1 | 0 | 1 | 1 | 1 | 1 | 1 | **0x7D**       | **0x82**     |
| 7     | 1 | 1 | 1 | 0 | 0 | 0 | 0 | **0x07**       | **0xF8**     |
| 8     | 1 | 1 | 1 | 1 | 1 | 1 | 1 | **0x7F**       | **0x80**     |
| 9     | 1 | 1 | 1 | 1 | 0 | 1 | 1 | **0x6F**       | **0x90**     |
| A     | 1 | 1 | 1 | 0 | 1 | 1 | 1 | **0x77**       | **0x88**     |
| B     | 0 | 0 | 1 | 1 | 1 | 1 | 1 | **0x7C**       | **0x83**     |
| C     | 1 | 0 | 0 | 1 | 1 | 1 | 0 | **0x39**       | **0xC6**     |
| D     | 0 | 1 | 1 | 1 | 1 | 0 | 1 | **0x5E**       | **0xA1**     |
| E     | 1 | 0 | 0 | 1 | 1 | 1 | 1 | **0x79**       | **0x86**     |
| F     | 1 | 0 | 0 | 0 | 1 | 1 | 1 | **0x71**       | **0x8E**     |

#### Explanation:
- **A, B, C, D, E, F, G** represent the segments of the 7-segment display.
  - **1** means the segment is ON.
  - **0** means the segment is OFF.

- **Common Cathode**:
  - In a **common cathode** configuration, a **HIGH** signal turns on the segment.
  - The hexadecimal values are based on this configuration, where the bits represent which segments are on (1) or off (0).

- **Common Anode**:
  - In a **common anode** configuration, a **LOW** signal turns on the segment.
  - The hexadecimal values for this configuration are inverted compared to the common cathode because the logic is reversed.


```c
/* ============================================================================
 *                      7-SEGMENT DISPLAY LOOKUP TABLES
 * ============================================================================ */
/**
 * @brief 7-Segment display encoding for hexadecimal digits (0-F)
 * @note Segment layout: ABCDEFG (bit 7 unused, bit 0 = G)
 *       
 *        A
 *       ---
 *    F |   | B
 *       -G-
 *    E |   | C
 *       ---
 *        D
 */

/* Common Cathode (Active HIGH - segments light when bit = 1) */
const uint8_t Seg7_cc[16] = 
{
    0x3F, /**< 0: ABCDEF   (0b00111111) */
    0x06, /**< 1: BC       (0b00000110) */
    0x5B, /**< 2: ABDEG    (0b01011011) */
    0x4F, /**< 3: ABCDG    (0b01001111) */
    0x66, /**< 4: BCFG     (0b01100110) */
    0x6D, /**< 5: ACDFG    (0b01101101) */
    0x7D, /**< 6: ACDEFG   (0b01111101) */
    0x07, /**< 7: ABC      (0b00000111) */
    0x7F, /**< 8: ABCDEFG  (0b01111111) */
    0x6F, /**< 9: ABCDFG   (0b01101111) */
    0x77, /**< A: ABCEFG   (0b01110111) */
    0x7C, /**< B: CDEFG    (0b01111100) */
    0x39, /**< C: ADEF     (0b00111001) */
    0x5E, /**< D: BCDEG    (0b01011110) */
    0x79, /**< E: ADEFG    (0b01111001) */
    0x71  /**< F: AEFG     (0b01110001) */
};

/* Common Anode (Active LOW - segments light when bit = 0) */
const uint8_t Seg7_ca[16] = 
{
    0xC0, /**< 0: ABCDEF   (0b11000000) */
    0xF9, /**< 1: BC       (0b11111001) */
    0xA4, /**< 2: ABDEG    (0b10100100) */
    0xB0, /**< 3: ABCDG    (0b10110000) */
    0x99, /**< 4: BCFG     (0b10011001) */
    0x92, /**< 5: ACDFG    (0b10010010) */
    0x82, /**< 6: ACDEFG   (0b10000010) */
    0xF8, /**< 7: ABC      (0b11111000) */
    0x80, /**< 8: ABCDEFG  (0b10000000) */
    0x90, /**< 9: ABCDFG   (0b10010000) */
    0x88, /**< A: ABCEFG   (0b10001000) */
    0x83, /**< B: CDEFG    (0b10000011) */
    0xC6, /**< C: ADEF     (0b11000110) */
    0xA1, /**< D: BCDEG    (0b10100001) */
    0x86, /**< E: ADEFG    (0b10000110) */
    0x8E  /**< F: AEFG     (0b10001110) */
};
```

```c
/* Common Cathode (Hex values for digits 0–15) */
const uint8_t Seg7_cc[16] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F, 0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71};

/* Common Anode (Hex values for digits 0–15) */
const uint8_t Seg7_ca[16] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90, 0x88, 0x83, 0xC6, 0xA1, 0x86, 0x8E};

```

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
