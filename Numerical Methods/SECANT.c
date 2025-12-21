#include <stdio.h>
#include <math.h>

// Function definition
double f(double x) {
    return x * x * x + x * x + 2 * x - 1;
}

int main() {
    double a = 0, b = 1, c = 0;
    int i = 0;

    printf("Hira Mani Rai\n");
    printf("--- Secant Method ---\n\n");

    printf("Function: x^3 + x^2 + 2x - 1\n");
    printf("Initial interval: (%.2f, %.2f)\n\n", a, b);

    // Check validity of initial guesses
    if (f(a) * f(b) >= 0) {
        printf("Invalid initial guess! Need opposite functional values.\n");
        return 1;
    }

    // Iteration loop
    do {
        i++;
        c = b - f(b) * (b - a) / (f(b) - f(a));
        a = b;
        b = c;

        printf("Iteration: %d\n", i);
        printf("Functional value f(c) = %.6f\n", f(c));
        printf("Approximate Root: %.6f\n\n", c);

        if (fabs(b - a) < 0.0005) {
            break;
        }
    } while (1);

    printf("The Approximate root of function x^3 + x^2 + 2x - 1 ");
    printf("after %d iterations: %.6f\n", i, c);

    return 0;
}

