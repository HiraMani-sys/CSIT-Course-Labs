#include<stdio.h>

// Function to evaluate polynomial using Horner’s method
double horner(int coeff[], int n, double x) {
    double result = coeff[0];
    for(int i=1; i<=n; i++) {
        result = result * x + coeff[i];
    }
    return result;
}

int main() {
    int n;
    printf("Enter degree of polynomial: ");
    scanf("%d", &n);

    int coeff[n+1];
    printf("Enter coefficients (from highest degree to constant term):\n");
    for(int i=0; i<=n; i++) {
        scanf("%d", &coeff[i]);
    }

    double x;
    printf("Enter value of x: ");
    scanf("%lf", &x);

    double result = horner(coeff, n, x);

    printf("Polynomial evaluated at x=%.3f is %.3f\n", x, result);
    return 0;
}

