#include <stdio.h>
#include <math.h>

double f(double x) {
    return -log10(1.0 / x) + sin(x);
}

double TrapezoidalRule(double a, double b, int n) {
    double h = (b - a) / n;
    double integral = 0.0;

    for (int i = 0; i <= n; i++) {
        double x = a + i * h;
        double fx = f(x);
        if (i == 0 || i == n) {
            integral += fx;
        }
        else {
            integral += 2 * fx;
        }
    }

    integral *= h / 2.0;
    return integral;
}

int main() {
    double a, b;
    int max;

    printf("적분할 시작 값을 입력하세요: ");
    scanf_s("%lf", &a);
    printf("적분할 끝 값을 입력하세요: ");
    scanf_s("%lf", &b);
    printf("시행할 최대 구간을 입력하세요(2^n): ");
    scanf_s("%d", &max);

    printf("\n");
    for (int i = 0; i <= max; i++) {
        int n = (int)pow(2, i);
        double result = TrapezoidalRule(a, b, n);
        printf("구간  %d    적분 결과: %.6f\n", n, result);
    }

    return 0;
}