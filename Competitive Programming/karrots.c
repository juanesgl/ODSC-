#include<stdio.h>

int main(){

    int n,m, j;
    char cha;

    scanf("%d, %d", &n, &m);

    for (j = 0; j < n; j++){
        scanf("%c", &cha);
    }
    printf("%d", m);
    return 0;
}