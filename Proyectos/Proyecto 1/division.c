#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void stripLeadingZeros(char *number) {
    int length = strlen(number);
    int i = 0;
    while (i < length-1 && number[i] == '0') i++;
    if (i > 0) memmove(number, number+i, length-i+1);
}


int compareNumbers(char *num1, char *num2) {
    stripLeadingZeros(num1);
    stripLeadingZeros(num2);
    {
        int len1 = strlen(num1), len2 = strlen(num2);
        if (len1 != len2) return len1 - len2;
        return strcmp(num1, num2);
    }
}


void subtract(char *minuend, char *subtrahend) {
    int lenMinuend = strlen(minuend), lenSubtrahend = strlen(subtrahend);
    int borrow = 0;
    int i;
    for (i = 0; i < lenMinuend; i++) {
        int digitMinuend = minuend[lenMinuend-1-i] - '0';
        int digitSubtrahend = (i < lenSubtrahend) ? subtrahend[lenSubtrahend-1-i] - '0' : 0;
        int difference = digitMinuend - digitSubtrahend - borrow;
        if (difference < 0) {
            difference += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        minuend[lenMinuend-1-i] = difference + '0';
    }
    stripLeadingZeros(minuend);
}


void divide(char *dividend, char *divisor, char *quotient, char *remainder) {
    int lenDividend = strlen(dividend);
    char currentSubstring[350005];
    currentSubstring[0] = '\0';
    int quotientIndex = 0;
    int i;

    for (i = 0; i < lenDividend; i++) {
        int length = strlen(currentSubstring);
        currentSubstring[length] = dividend[i];
        currentSubstring[length+1] = '\0';
        stripLeadingZeros(currentSubstring);

        {
            int count = 0;
            while (compareNumbers(currentSubstring, divisor) >= 0) {
                subtract(currentSubstring, divisor);
                count++;
            }
            quotient[quotientIndex++] = count + '0';
        }
    }
    quotient[quotientIndex] = '\0';
    stripLeadingZeros(quotient);
    strcpy(remainder, currentSubstring);
    if (strlen(remainder) == 0) strcpy(remainder, "0");
}

int main() {
    int numTests;
    scanf("%d", &numTests);
    while (numTests--) {
        char dividend[350005], divisor[350005];
        char quotient[350005], remainder[350005];
        scanf("%s %s", dividend, divisor);

        divide(dividend, divisor, quotient, remainder);

        printf("%s\n%s\n", quotient, remainder);
    }
    return 0;
}