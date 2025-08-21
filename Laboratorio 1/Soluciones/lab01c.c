#include <stdlib.h>
#include <stdio.h>

#define MAX 2000  

int main() {
    int tc, i, j, n;
    float v[MAX], min;

    scanf("%d", &tc);

    for (i = 0; i < tc; i++) {
        scanf("%d", &n);

        for (j = 0; j < n; j++) {
            scanf("%f", &v[j]);  
        }

        min = v[0];

        for (j = 1; j < n; j++) {
            if (v[j] < min) {
                min = v[j];
            }
        }

        printf("%f\n", min);  
    }

    return 0;
}

