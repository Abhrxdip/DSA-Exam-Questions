#include <stdio.h>

int fibonacci(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int factorial(int n) {
    if (n == 0 || n == 1) return 1;
    return n * factorial(n - 1);
}

int main() {
    int n;

    printf("=== Fibonacci Series (Recursive) ===\n");
    printf("Enter number of terms: ");
    scanf("%d", &n);
    printf("Fibonacci series: ");
    for (int i = 0; i < n; i++)
        printf("%d ", fibonacci(i));
    printf("\n");

    printf("\n=== Factorial (Recursive) ===\n");
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("Factorial of %d = %d\n", n, factorial(n));

    return 0;
}
