#include<stdlib.h>
#include<stdio.h>



int main(){


    int tc, i;

    long dividen, divisor;

    scanf("%d", &tc);

    for (i = 0; i < tc;i ++){
        scanf("%ld %ld", &dividen, &divisor);
        printf("%ld %ld \n", dividen, divisor);
    }

    return 0;

}