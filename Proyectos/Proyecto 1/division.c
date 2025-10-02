#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>


<<<<<<< Updated upstream
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
=======
int dividend[MAX], divisor[MAX], temp[MAX], quotient[MAX];
int lenA, lenB, lenTemp, qlen;

int compare(int arr1[], int len1, int arr2[], int len2) {
    int i;
    if (len1 > len2) return 1;
    if (len1 < len2) return -1;
    for (i = 0; i < len1; i++) {
        if (arr1[i] > arr2[i]) return 1;
        if (arr1[i] < arr2[i]) return -1;
    }
    return 0;
}

void subtract(int arr1[], int *len1, int arr2[], int len2) {
    int i, j, borrow = 0;
    for (i = 0; i < *len1; i++) {
        int a = arr1[*len1 - 1 - i];
        int b = (i < len2) ? arr2[len2 - 1 - i] : 0;
        int val = a - b - borrow;
        if (val < 0) {
            val += 10;
>>>>>>> Stashed changes
            borrow = 1;
        } else {
            borrow = 0;
        }
<<<<<<< Updated upstream
        minuend[lenMinuend-1-i] = difference + '0';
=======
        arr1[*len1 - 1 - i] = val;
    }

    while (*len1 > 1 && arr1[0] == 0) {
        for (j = 0; j < *len1 - 1; j++) {
            arr1[j] = arr1[j + 1];
        }
        (*len1)--;
>>>>>>> Stashed changes
    }
    stripLeadingZeros(minuend);
}

void multiply(int arr[], int len, int digit, int result[], int *resLen) {
    int i, carry = 0;
    if (digit == 0) {
        result[0] = 0;
        *resLen = 1;
        return;
    }
    
    *resLen = 0;
    for (i = len - 1; i >= 0; i--) {
        int val = arr[i] * digit + carry;
        result[(*resLen)++] = val % 10;
        carry = val / 10;
    }
    while (carry > 0) {
        result[(*resLen)++] = carry % 10;
        carry /= 10;
    }
    
    for (i = 0; i < *resLen / 2; i++) {
        int t = result[i];
        result[i] = result[*resLen - 1 - i];
        result[*resLen - 1 - i] = t;
    }
}


<<<<<<< Updated upstream
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
=======
void divide(char A[], char B[]) {
    int i, j;
    int multi_res[MAX];
    int multi_len;
    char *ptrA = A;
    char *ptrB = B;

    lenA = 0;
    lenB = 0;
    lenTemp = 0;
    qlen = 0;

    while (*ptrA != '\0') {
        dividend[lenA++] = *ptrA - '0';
        ptrA++;
    }
    while (*ptrB != '\0') {
        divisor[lenB++] = *ptrB - '0';
        ptrB++;
    }

    if (lenB == 1 && divisor[0] == 0) {
        printf("Error: Division by zero\n");
        return;
    }
    
    if (compare(dividend, lenA, divisor, lenB) < 0) {
        printf("0\n");
        for (i = 0; i < lenA; i++) {
            printf("%d", dividend[i]);
        }
        printf("\n");
        return;
    }

    for (i = 0; i < lenA; i++) {
        temp[lenTemp++] = dividend[i];

        if (lenTemp > 1 && temp[0] == 0) {
            for (j = 0; j < lenTemp - 1; j++) {
                temp[j] = temp[j + 1];
            }
            lenTemp--;
        }

        quotient[qlen] = 0;
        if (compare(temp, lenTemp, divisor, lenB) >= 0) {
            for (quotient[qlen] = 9; quotient[qlen] >= 0; quotient[qlen]--) {
                multiply(divisor, lenB, quotient[qlen], multi_res, &multi_len);
                if (compare(temp, lenTemp, multi_res, multi_len) >= 0) {
                    subtract(temp, &lenTemp, multi_res, multi_len);
                    break;
                }
            }
        }
        qlen++;
    }

    i = 0;
    while (i < qlen - 1 && quotient[i] == 0) i++;
    for (; i < qlen; i++) {
        printf("%d", quotient[i]);
    }
    printf("\n");

    if (lenTemp == 0) {
        printf("0\n");
    } else {
        i = 0;
        while (i < lenTemp - 1 && temp[i] == 0) {
            i++;
        }
        for (; i < lenTemp; i++) {
            printf("%d", temp[i]);
        }
        printf("\n");
>>>>>>> Stashed changes
    }
    quotient[quotientIndex] = '\0';
    stripLeadingZeros(quotient);
    strcpy(remainder, currentSubstring);
    if (strlen(remainder) == 0) strcpy(remainder, "0");
}

int main() {
<<<<<<< Updated upstream
    int numTests;
    scanf("%d", &numTests);
    while (numTests--) {
        char dividend[350005], divisor[350005];
        char quotient[350005], remainder[350005];
        scanf("%s %s", dividend, divisor);

        divide(dividend, divisor, quotient, remainder);

        printf("%s\n%s\n", quotient, remainder);
=======
    int t;
    char A[MAX], B[MAX];
    if (scanf("%d", &t) != 1) return 1;
    while (t--) {
        scanf("%s", A);
        scanf("%s", B);
        divide(A, B);
>>>>>>> Stashed changes
    }
    return 0;
}