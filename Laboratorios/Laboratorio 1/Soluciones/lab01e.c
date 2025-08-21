#include <stdio.h>

void addition(float a, float b) {
    printf("%f\n", a + b);
}

void substraction(float a, float b) {
    printf("%f\n", a - b);
}

void multipication(float a, float b) {
    printf("%f\n", a * b);
}

void division(float a, float b) {
    if (b == 0) {
        printf("Error: Division by zero\n");
        return;
    }
    printf("%f\n", a / b);
}

int main() {
    int tc;
    int i;
    float a, b;
    char operator;

    scanf("%d", &tc);

    for (i = 0; i < tc; i++) {
        scanf(" %c", &operator); 
        scanf("%f", &a);
        scanf("%f", &b);

        switch(operator) {
            case '+': addition(a, b); break;
            case '-': substraction(a, b); break;
            case '*': multipication(a, b); break;
            case '/': division(a, b); break;
            default: printf("Operador no valido\n");
        }
    }

    return 0;
}

