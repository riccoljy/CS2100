// CS2100 Computer Organisation
// AY2024/2025 Semester 1
// National University of Singapore.
// Assignment 1 Question 1.
// All rights reserved.
//
// Start by filling in the following variables which main() will print out so as to identify yourself.
// Failure to full in the details correctly will be penalised.
//

const char *student_number = "A0269596A";
const char *student_name = "Ricco Lim";
const char *student_tut_grp = "T07";

#include <stdio.h>
#include <stdlib.h>

int lengthOfInt(int x) {
    int length = 0, copy = x;
    while (copy > 0) {
        copy /= 10;
        length++;
    }
    return length;
}

char* intToString(int x) {
    int length = lengthOfInt(x);
    char* str = (char *)malloc((length + 1) * sizeof(char));
    for (int i = length - 1; i >= 0; i--) {
        int remainder = x % 10;
        x /= 10;
        str[i] = remainder + '0';
    }
    str[length] = '\0';
    return str;
}

int strLength(char* str) {
    int i = 0;
    while (str[i] != '\0') i++;
    return i;
}

int isOdd(int x) {return x%2;}

long power(int base, int pow) {
    if (pow == 0) return 1;
    long result = base;
    for (int i = 1; i < pow; i++) {result *= base;}
    return result;
}

void flipBits(char *bits, int n) {
    for (int i = 0; i < n; i++) {
        bits[i] = bits[i] - '0' ? '0' : '1';
    }
}

void flipNegativeBits(char *bits, int n) {
    int reachedFirst1 = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (bits[i] == '0') continue;
        else if (bits[i] == '1' && !reachedFirst1) {
            reachedFirst1 = 1;
            flipBits(bits, i);
            return;
        }
    }
}

/**
 * @brief This function will convert the integer input that is represented in two's complement 
 *        to one that is in one's complement, and return that as the result.
 *
 * @param x The 2's complement input integer to be converted.
 *
 * @return  The one's complement representation of x.
 *
 **/
int twos_to_ones(int x)
{
    return x < 0 ? x - 1 : x;
}

/**
 * @brief Converts an integer to its n-bit binary string representation.
 *
 * This function generates an n-bit sign-extended one's-complement binary
 * string representation of the given integer `i` and stores it in `s`.
 *
 * @param i The input integer to be converted.
 * @param n The number of bits required for the binary representation.
 * @param s Pointer to the output string where the binary representation
 *          will be stored. The space allocated for `s` must accommodate
 *          `n + 1` characters (including the null-terminator, i.e., 0). The MSB 
 *          is always at the zero'ed position of the string and the LSB 
 *          is the last character in the string before the null-terminator.
 *
 * @note The function assumes that the longest integer to be represented
 *       is 32 bits.
 *
 **/
void binstr(int i, int n, char *s)
{
    int isNegative = i < 0;
    for (int j = n - 1; j >= 0; j--) {
        s[j] = !isOdd(i) || !i ? '0' : '1';
        i /= 2;
    }
    s[n] = '\0';
    if (isNegative) flipNegativeBits(s, n);
}

/**
 * @brief Converts an n-bit binary string to its corresponding integer value.
 *
 * This function reverses the operation of `binstr`, converting an n-character
 * long null-terminated binary string `s` in one's-complement form to its
 * corresponding integer value in two's complement representation.
 *
 * @param s Pointer to the input string representing the binary number in
 *          one's-complement form. The string is assumed to be exactly `n`
 *          characters long, followed by a null-terminator.
 * @param n The number of bits in the binary string (not including the
 *          null-terminator).
 *
 * @return The integer value corresponding to the binary string `s`.
 *
 * @note If `s` contains any character other than '0' or '1', or if `n`
 *       exceeds 32, the function will return an undefined (arbitrary) value.
 *
 **/
int str2int(char *s, int n)
{
    int res = 0, largestBitValue = 1;
    for (int i = n - 1; i > 0; i--) {
        int index = (n - 1) - i;
        if (s[i] == '1') res += largestBitValue;
        largestBitValue *= 2;
    }
    if (s[0] == '1') res -= largestBitValue - 1;
    return res;
}

/**
 * @brief Validates whether the input integer `x` fits within an n-bit
 *        one's-complement representation.
 *
 * This function checks if the input integer `x` can be represented within
 * an n-bit one's-complement format. If `x` fits, the function returns 0.
 * If `x` is out of range, the function returns the nearest limit, which
 * will be negative if `x` is negative.
 *
 * @param x The input integer to be validated.
 * @param n The number of bits for the one's-complement representation.
 *
 * @return 0 if `x` fits within the n-bit one's-complement range, otherwise
 *         the nearest limit is returned.
 *
 **/
int validate_1s_complement(int x, int n)
{
    int largestBitValue = 1, currTotal = 0, isNegative = (x < 0);
    if (isNegative) x -= 2*x;
    for (int i = 0; i < n - 1; i++) {
        currTotal += largestBitValue;
        largestBitValue *= 2;
        if (currTotal >= x) return 0;
    }
    return isNegative ? -currTotal : currTotal;
}

/**
 * @brief Checks for carry out of the MSB by checking the carry string.
 *
 * @param carry_str The (n+1) character carry string generated by the addition
 *                  process.
 * @param n The number of bits for the one's-complement representation.
 *
 * @return 0 if the MSB of the carry string is the character '0'.
 * @return 1 if the MSB of the carry string is the character '1'.
 *
 **/
int check_carryout(char *carry_str)
{
    return carry_str[0] - '0';
}

/**
 * @brief Checks for overflow after one's complement addition inspecting the 
 *        two inputs (as strings) and the output (as a string). 
 *
 * @param op1 A n-character long null-terminated string of '0' and '1' representing the first
 *            operand of the addition. 
 *
 * @param op2 A n-character long null-terminated string of '0' and '1' representing the second 
 *            operand of the addition. 
 *
 * @param sum A n-character long null-terminated string of '0' and '1' representing the sum
 *            (i.e., result) of the addition. 
 *
 * @return 0 if there is no overflow.
 * @return 1 if there is an overflow.
 *
 * @note The three inputs must be of the same length.
 *
 **/
int check_overflow(char *op1, char *op2, char *sum)
{
    return (op1[0] == op2[0] && op1[0] != sum[0]);
}

/**
 * @brief Performs n-bit unsigned addition of two binary strings.
 *
 * This function adds two n-bit unsigned binary numbers represented by the
 * strings `x` and `y`. The result is stored in the string `z`, and the carry
 * out of each bit position is stored in the string `c`.
 *
 * @param n The number of bits in the input strings `x` and `y`.
 *
 * @param x Pointer to the first input binary string. The string is assumed
 *          to be `n` characters long, followed by a null-terminator.
 *
 * @param y Pointer to the second input binary string. The string is assumed
 *          to be `n` characters long, followed by a null-terminator.
 *
 * @param z Pointer to the output string where the result will be stored.
 *          The space allocated for `z` must accommodate `n` characters and
 *          a null-terminator.
 *
 * @param c Pointer to the output string where the carry bits will be stored.
 *          The space allocated for `c` must accommodate `n + 1` characters
 *          (including the carry out and the null-terminator).
 *
 * @return 0 if the operation is successful, -1 if any error occurs.
 *
 * @note The function assumes that the input strings `x` and `y` consist
 *       only of the characters '0' and '1'.
 *
 * @note The MSB is always at the zero'ed position of the string representing
 *       the ones-complement number, and the LSB is the last character in that 
 *       string before the null-terminator.
 *
 **/
int perform_addition(int n, char *x, char *y, char *z, char *c)
{
    c[n] = '0';
    for (int i = n - 1; i >= 0; i--) {
        int sum = x[i] + y[i] + c[i+1] - 3*'0';
        c[i] = (sum > 1) ? '1' : '0';
        z[i] = (sum == 2 || sum == 0) ? '0' : '1';
    }
    z[n] = '\0';
    c[n+1] = '\0';
    return 0;
}
