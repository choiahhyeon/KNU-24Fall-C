#include <stdio.h>
#include <math.h>

void solve(int a, int b, int c) {
    double D = (double)b * b - 4 * a * c;

    if (D < 0) {
        printf("\n����� �����ϴ�.\n");
    }
    else if (D == 0) {
        double answer = -b / (2.0 * a);
        printf("\n�߱�: %.2f\n", answer);
    }
    else {
        double answer1 = (-b + sqrt(D)) / (2.0 * a);
        double answer2 = (-b - sqrt(D)) / (2.0 * a);
        printf("\n�� ���� ���� �ٸ� �Ǳ�:\n");
        printf("��1: %.2f\n", answer1);
        printf("��2: %.2f\n", answer2);
    }
}

int main() {
    int a, b, c;

    printf("������������ ��� a, b, c�� �Է��ϼ���.\n");
    printf("a: ");
    scanf_s("%d", &a);
    printf("b: ");
    scanf_s("%d", &b);
    printf("c: ");
    scanf_s("%d", &c);

    solve(a, b, c);

    return 0;
}