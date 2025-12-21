#include <stdio.h>
#include <math.h>

// Function definition
double f(double x) {
    return x * x * x + 3 * x * x - 2 * x - 3;
}

// Derivative definition
double df(double x) {
    return 3 * x * x + 6 * x - 2;
}

int main() {
    double x = 1, xn;
    int iteration = 0;

    printf("Hira Mani Rai\n");
    printf("--- Newton Raphson Method ---\n\n");

    printf("Function: x^3 + 3*x^2 - 2*x - 3\n");
    printf("Initial Guess: %.2f\n\n", x);

    // Check derivative at initial guess
    if (fabs(df(x)) < 1e-8) {
        printf("Derivative too small.\n");
        return 1;
    }

    // Iteration loop
    do {
        iteration++;
        xn = x - f(x) / df(x);

        printf("Iteration: %d\n", iteration);
        printf("Functional value f(x) = %.6f\n", f(x));
        printf("Derivative value f'(x) = %.6f\n", df(x));
        printf("Approximate Root: %.6f\n\n", xn);

        if (fabs(xn - x) < 0.0005) {
            break;
        }
        x = xn;
    } while (1);

    printf("The Approximate root of function x^3 + 3*x^2 - 2x - 3 ");
    printf("after %d iterations: %.6f\n", iteration, xn);

    return 0;
}

