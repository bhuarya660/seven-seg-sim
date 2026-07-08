/*
 * 7-Segment Display Digit Simulator (C)
 * -----------------------------------------------------------------
 * Simulates how a 7-segment display shows digits 0-9, without any
 * physical display or hardware. Each digit is represented by which
 * of its 7 segments (a-g) are ON, exactly the way a real 7-segment
 * driver circuit encodes digits - the same encoding used in digital
 * logic / embedded display driver projects.
 *
 *      a
 *    -----
 *  f|     |b
 *   |  g  |
 *    -----
 *  e|     |c
 *   |     |
 *    -----
 *      d
 *
 * Segment order used below: {a, b, c, d, e, f, g}
 * 1 = segment ON, 0 = segment OFF
 */

#include <stdio.h>

/* Segment patterns for digits 0-9 */
int segment_table[10][7] = {
    /* a  b  c  d  e  f  g */
    {  1, 1, 1, 1, 1, 1, 0 }, /* 0 */
    {  0, 1, 1, 0, 0, 0, 0 }, /* 1 */
    {  1, 1, 0, 1, 1, 0, 1 }, /* 2 */
    {  1, 1, 1, 1, 0, 0, 1 }, /* 3 */
    {  0, 1, 1, 0, 0, 1, 1 }, /* 4 */
    {  1, 0, 1, 1, 0, 1, 1 }, /* 5 */
    {  1, 0, 1, 1, 1, 1, 1 }, /* 6 */
    {  1, 1, 1, 0, 0, 0, 0 }, /* 7 */
    {  1, 1, 1, 1, 1, 1, 1 }, /* 8 */
    {  1, 1, 1, 1, 0, 1, 1 }  /* 9 */
};

char segment_names[7] = {'a', 'b', 'c', 'd', 'e', 'f', 'g'};

/* Print which segments are ON for a given digit */
void print_segment_states(int digit) {
    printf("Digit %d -> segments ON: ", digit);
    for (int i = 0; i < 7; i++) {
        if (segment_table[digit][i] == 1) {
            printf("%c ", segment_names[i]);
        }
    }
    printf("\n");
}

/* Draw an ASCII-art 7-segment rendering of the digit */
void draw_digit(int digit) {
    int *seg = segment_table[digit];

    /* segment order: a b c d e f g */
    printf(seg[0] ? " _ \n" : "   \n");                              /* a */
    printf("%c %c%c\n", seg[5] ? '|' : ' ', ' ', seg[1] ? '|' : ' '); /* f, b */
    printf(seg[6] ? " - \n" : "   \n");                               /* g */
    printf("%c %c%c\n", seg[4] ? '|' : ' ', ' ', seg[2] ? '|' : ' '); /* e, c */
    printf(seg[3] ? " - \n" : "   \n");                               /* d */
}

int main(void) {
    printf("7-Segment Display Digit Simulator\n");
    printf("==================================\n\n");

    for (int digit = 0; digit <= 9; digit++) {
        draw_digit(digit);
        print_segment_states(digit);
        printf("\n");
    }

    return 0;
}
