#include <stdio.h>
#include <stdlib.h>

int mcd(int a, int b){

    while (b != 0){

        int temp = b;
        b = a % b; 
        a = temp;
    }    
    return a;
}

int main() {
    int tc, i;
    long numerator, denominator, n;
    long common_divisor;

    scanf("%d", &tc);

    for (i = 0; i < tc; i++) {
        scanf("%ld", &numerator);
        scanf("%ld", &denominator);
     
        if (numerator == 0) {
            printf("0\n");
            printf("0\n");
            continue;
        }

        while (numerator != 1) {
            
            if (numerator == 0) break;
            
            n = denominator / numerator;
            if (denominator % numerator != 0) {
                n++;
            }

            printf("%ld\n", n);
            
            numerator = numerator * n - denominator;
            denominator = denominator * n;
          
            if (numerator != 0) {
                common_divisor = mcd(numerator, denominator);
                numerator /= common_divisor;
                denominator /= common_divisor;
            }
        }
       
        if (numerator == 1) {
            printf("%ld\n", denominator);
        }
        
        printf("0\n");
    }

    return 0;
}