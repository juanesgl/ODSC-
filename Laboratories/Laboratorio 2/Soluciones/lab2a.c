#include <stdio.h>
#include <math.h>


void cuadratic(float a, float b, float c) {
    float discriminant, disc_root;
    float n1, n2;

    discriminant = b * b - 4 * a * c;

    if (discriminant < 0) {
        printf("no roots\n");
        return;
    }

    disc_root = sqrt(discriminant);

    n1 = (-b + disc_root) / (2 * a);
    n2 = (-b - disc_root) / (2 * a);

    if (n1 == n2) {
        printf("%.2f\n", n1);
    } else {
        printf("%.2f\n", n1);
        printf("%.2f\n", n2);
    }
}

int main() {
    int tc, i;
    float a, b, c;

    scanf("%d", &tc);

    for (i = 0; i < tc; i++) {
        scanf("%f", &a);
        scanf("%f", &b);
        scanf("%f", &c);
        cuadratic(a, b, c);
    }

    return 0;
}
