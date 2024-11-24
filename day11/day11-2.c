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

    printf("������ ���� ���� �Է��ϼ���: ");
    scanf_s("%lf", &a);
    printf("������ �� ���� �Է��ϼ���: ");
    scanf_s("%lf", &b);
    printf("������ �ִ� ������ �Է��ϼ���(2^n): ");
    scanf_s("%d", &max);

    printf("\n");
    for (int i = 0; i <= max; i++) {
        int n = (int)pow(2, i);
        double result = TrapezoidalRule(a, b, n);
        printf("����  %d    ���� ���: %.6f\n", n, result);
    }

    return 0;
}