#include <stdio.h>
#include <stdlib.h>

int validate_1s_complement(int x, int n) {
    int largestBitValue = 1, currTotal = 0, isNegative = (x < 0);
    if (isNegative) x -= 2*x;
    for (int i = 0; i < n; i++) {
        currTotal += largestBitValue;
        largestBitValue *= 2;
        if (currTotal >= x) return 0;
    }
    return isNegative ? -(currTotal - 1) : currTotal;
}

long power(int base, int pow) {
    long result = base;
    for (int i = 1; i < pow; i++) {result *= base;}
    return result;
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


int isOdd(int x) {return x%2;}

void binstr(int i, int n, char *s)
{
    for (int j = n - 1; j >= 0; j--) {
        s[j] = !isOdd(i) || !i ? '0' : '1';
        i /= 2;
    }
    s[n] = '\0';
}

int main(){
    char storage[33];
    binstr(6, 3, storage);
    printf(storage);
    return 0;
}