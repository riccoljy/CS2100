#include <stdio.h>
#include <string.h>
#include <ctype.h>

int hexToDecimal(char[], size_t);
int hexVal(char);

int main(void)
{
	char hex[31];
	size_t len;

	printf("Enter up to 30 hexadecimal digits (eg. 10AB): ");
	fgets(hex, 31, stdin);
	len = strlen(hex);

	/* End-of-Line Check */
	if (hex[len - 1] == '\n')
	{
		len = len - 1;
		hex[len] = '\0';
	}

	printf("You entered: %s\n", hex);
	printf("The value in decimal is: %d\n", hexToDecimal(hex, len));

	return 0;
}

int hexVal(char hex)
{
	switch (toupper(hex))
	{
	case '0':
		return 0;
	case '1':
		return 1;
	case '2':
		return 2;
	case '3':
		return 3;
	case '4':
		return 4;
	case '5':
		return 5;
	case '6':
		return 6;
	case '7':
		return 7;
	case '8':
		return 8;
	case '9':
		return 9;
	case 'A':
		return 10;
	case 'B':
		return 11;
	case 'C':
		return 12;
	case 'D':
		return 13;
	case 'E':
		return 14;
	case 'F':
		return 15;
	}
	return 0;
}

long power(int base, int pow) {
    if (pow == 0) return 1;
    long result = base;
    for (int i = 1; i < pow; i++) {result *= base;}
    return result;
}

int hexToDecimal(char hex[], size_t size)
{
	printf("test %d", sizeof(hex)/sizeof(hex[0]));
	char *currentPtr = &(hex[size - 1]);
	int result = 0, currentIndex = 0;
	while (currentPtr != hex - 1) result += hexVal(*(currentPtr--)) * power(16, currentIndex++);
	return result;
}
