# seven-seg-sim
# 7-Segment Display Digit Simulator (C)

Simulates how a 7-segment display encodes and shows digits 0-9, without needing a physical display or any hardware.

## Concept
Each digit is represented by a 7-element array showing which segments (a–g) are ON or OFF — the exact same encoding scheme used by real 7-segment display driver circuits and decoder ICs (e.g. the 7447 BCD-to-7-segment decoder). The program looks up the pattern for a digit and:
1. Prints which segments would be lit (`a b c d e f`)
2. Draws an ASCII-art rendering of the digit

## Build & Run
```
gcc -Wall -o seven_seg seven_seg.c
./seven_seg
```

## Why this design
- The `segment_table` is a direct software model of a hardware truth table — the same kind of lookup table used in decoder logic, connecting directly to Digital Electronics & Logic Design coursework.
- No dynamic memory, no pointers beyond array indexing — deliberately simple, beginner-appropriate C.
- Ties naturally to prior Verilog counter work: a counter's output could drive exactly this kind of 7-segment decoding on real hardware.

## Possible extensions
- Add hexadecimal digits (A–F)
- Take digit input from the user instead of looping 0–9
- Model a decimal point segment (dp)
- Port the same segment_table encoding to a real 7-segment display on a microcontroller once hardware is available
