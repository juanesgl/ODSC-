#include <stdio.h>
#include <stdlib.h>

#define MAX 350001


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
            borrow = 1;
        } else {
            borrow = 0;
        }
        arr1[*len1 - 1 - i] = val;
    }
   
    while (*len1 > 1 && arr1[0] == 0) {
        for (j = 0; j < *len1 - 1; j++) {
            arr1[j] = arr1[j + 1];
        }
        (*len1)--;
    }
}


void divide(char A[], char B[]) {
    int i, j;

    lenA = 0; lenB = 0; lenTemp = 0; qlen = 0;

    while (A[lenA] != '\0') {
        dividend[lenA] = A[lenA] - '0';
        lenA++;
    }
    while (B[lenB] != '\0') {
        divisor[lenB] = B[lenB] - '0';
        lenB++;
    }

    for (i = 0; i < lenA; i++) {
        
        temp[lenTemp] = dividend[i];
        lenTemp++;

        while (lenTemp > 1 && temp[0] == 0) {
            for (j = 0; j < lenTemp - 1; j++) temp[j] = temp[j + 1];
            lenTemp--;
        }

        
        int count = 0;
        while (compare(temp, lenTemp, divisor, lenB) >= 0) {
            subtract(temp, &lenTemp, divisor, lenB);
            count++;
        }
        quotient[qlen++] = count;
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
        for (i = 0; i < lenTemp; i++) {
            printf("%d", temp[i]);
        }
        printf("\n");
    }
}

int main() {
    int t;
    char A[MAX], B[MAX];
    if (scanf("%d", &t) != 1) return 1;

    while (t--) {
        scanf("%s", A);
        scanf("%s", B);
        divide(A, B);
    }

    return 0;
}