#include<stdlib.h>
#include<stdio.h>
#define MAX 10

int mcd(int a, int b){

    while (b != 0){

        int temp = b;
        b = a % b; 
        a = temp;
    }    
    return a;
}

int vector_sum(int v[], int n) {
    int i, suma = 0;
    for (i = 0; i < n; i++) {
        suma += v[i];
    }
    return suma;
}


int main(){


    int tc, i,j;
    int belgium, england, norway, ireland, france;
    int mcd_result;
    int airplane_mcd[5];

    scanf("%d", &tc);

    for (i = 0; i < tc; i++){

        scanf("%d", &belgium);
        scanf("%d", &england);
        scanf("%d", &norway);
        scanf("%d", &ireland);
        scanf("%d", &france);

        mcd_result = mcd(mcd(mcd(mcd(belgium, england), norway), ireland), france);

        airplane_mcd[0] = belgium / mcd_result;
        airplane_mcd[1] = england / mcd_result; 
        airplane_mcd[2] = norway / mcd_result;
        airplane_mcd[3] = ireland / mcd_result;
        airplane_mcd[4] = france / mcd_result;


        printf("%d\n", mcd_result);

        for (j = 0; j < 5; j++){
            printf("%d\n", airplane_mcd[j]);

        }

        printf("%d\n", vector_sum(airplane_mcd, 5));
        
    }

    return 0;

}