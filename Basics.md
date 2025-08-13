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

| Digit | A | B | C | D | E | F | G | Common Cathode (Hex) | Common Anode (Hex) |
|-------|---|---|---|---|---|---|---|----------------------|--------------------|
| 0     | 1 | 1 | 1 | 1 | 1 | 1 | 0 | **0x3F**             | **0xC0**           |
| 1     | 0 | 1 | 1 | 0 | 0 | 0 | 0 | **0x06**             | **0xF9**           |
| 2     | 1 | 1 | 0 | 1 | 1 | 0 | 1 | **0xB6**             | **0x49**           |
| 3     | 1 | 1 | 1 | 1 | 0 | 0 | 1 | **0x9E**             | **0x41**           |
| 4     | 0 | 1 | 1 | 0 | 0 | 1 | 1 | **0x66**             | **0x99**           |
| 5     | 1 | 0 | 1 | 1 | 0 | 1 | 1 | **0x5E**             | **0x62**           |
| 6     | 1 | 0 | 1 | 1 | 1 | 1 | 1 | **0x7E**             | **0x32**           |
| 7     | 1 | 1 | 1 | 0 | 0 | 0 | 0 | **0x4E**             | **0xB9**           |
| 8     | 1 | 1 | 1 | 1 | 1 | 1 | 1 | **0x7F**             | **0x30**           |
| 9     | 1 | 1 | 1 | 1 | 0 | 1 | 1 | **0x6E**             | **0x51**           |
| A     | 1 | 1 | 1 | 0 | 1 | 1 | 1 | **0x7B**             | **0x5A**           |
| B     | 0 | 1 | 1 | 1 | 1 | 1 | 1 | **0x3E**             | **0x6A**           |
| C     | 1 | 0 | 0 | 1 | 1 | 1 | 1 | **0x5C**             | **0x74**           |
| D     | 0 | 1 | 1 | 1 | 1 | 0 | 1 | **0x7A**             | **0x3A**           |
| E     | 1 | 0 | 0 | 1 | 1 | 1 | 1 | **0x7D**             | **0x6E**           |
| F     | 1 | 0 | 0 | 0 | 1 | 1 | 1 | **0x5F**             | **0x5E**           |

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
/* Common Cathode (Hex values for digits 0-15) */
const uint8_t Seg7_cc[16] = 
{
    0x3F, // 0
    0x06, // 1
    0xB6, // 2
    0x9E, // 3
    0x66, // 4
    0x5E, // 5
    0x7E, // 6
    0x4E, // 7
    0x7F, // 8
    0x6E, // 9
    0x7B, // A
    0x3E, // B
    0x5C, // C
    0x7A, // D
    0x7D, // E
    0x5F  // F
};

/* Common Anode (Hex values for digits 0-15) */
const uint8_t Seg7_ca[16] = 
{
    0xC0, // 0
    0xF9, // 1
    0x49, // 2
    0x41, // 3
    0x99, // 4
    0x62, // 5
    0x32, // 6
    0xB9, // 7
    0x30, // 8
    0x51, // 9
    0x5A, // A
    0x6A, // B
    0x74, // C
    0x3A, // D
    0x6E, // E
    0x5E  // F
};
```

```c
/* Common Cathode (Hex values for digits 0–15) */
const uint8_t Seg7_cc[16] = { 0x3F, 0x06, 0xB6, 0x9E, 0x66, 0x5E, 0x7E, 0x4E, 0x7F, 0x6E, 0x7B, 0x3E, 0x5C, 0x7A, 0x7D, 0x5F };

/* Common Anode (Hex values for digits 0–15) */
const uint8_t Seg7_ca[16] = { 0xC0, 0xF9, 0x49, 0x41, 0x99, 0x62, 0x32, 0xB9, 0x30, 0x51, 0x5A, 0x6A, 0x74, 0x3A, 0x6E, 0x5E };
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
