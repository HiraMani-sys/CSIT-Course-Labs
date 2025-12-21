#include <stdio.h>
#include <math.h>

// Function definition
double f(double x) {
    return x * x - 3 * x + 2;
}

// Iteration function
double g(double x) {
    return (x * x + 2) / 3.0;
}

// Derivative of g(x)
double dg(double x) {
    return (2 * x) / 3.0;
}

int main() {
    double x = 0.0, xn = 0.0;
    int iteration = 0;

    printf("Hira Mani Rai\n");
    printf("--- Fixed Point Iteration ---\n\n");

    printf("Initial guess: %.2f\n\n", x);

    // Check convergence condition
    if (fabs(dg(x)) >= 1) {
        printf("Warning: Iteration may diverge!\n\n");
        return 1;
    }

    // Iteration loop
    do {
        iteration++;
        xn = g(x);

        printf("Iteration: %d\n", iteration);
        printf("Functional value f(x) = %.6f\n", f(x));
        printf("Approximate Root: %.6f\n\n", xn);

        if (fabs(xn - x) < 0.0005) {
            break;
        }

        x = xn;
    } while (1);

    printf("The Approximate root of function x^2 - 3*x + 2 ");
    printf("after %d iterations: %.6f\n", iteration, x);

    return 0;
}

