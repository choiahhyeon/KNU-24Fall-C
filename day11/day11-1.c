#include <stdio.h>
#include <math.h>

void solve(double a, double b, double c) {
    double D = b * b - 4 * a * c;

    if (D > 0) {
        double answer1 = (-b + sqrt(D)) / (2 * a);
        double answer2 = (-b - sqrt(D)) / (2 * a);
        printf("\n�� ���� ���� �ٸ� �Ǳ�\n");
        printf("��1: %.2f\n", answer1);
        printf("��2: %.2f\n", answer2);
    }
    else if (D == 0) {
        double answer = -b / (2 * a);
        printf("\n�߱�: %.2f\n", answer);
    }
    else {
        printf("\n����� �����ϴ�.\n");
    }
}

int main() {
    double a, b, c;

    printf("������������ ��� a, b, c�� �Է��ϼ���.\n");
    printf("a: ");
    scanf_s("%lf", &a);
    printf("b: ");
    scanf_s("%lf", &b);
    printf("c: ");
    scanf_s("%lf", &c);

    solve(a, b, c);

    return 0;
}