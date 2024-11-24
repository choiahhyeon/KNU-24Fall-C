#include <stdio.h>
#include <math.h>

void solve(double a, double b, double c) {
    double D = b * b - 4 * a * c;

    if (D > 0) {
        double answer1 = (-b + sqrt(D)) / (2 * a);
        double answer2 = (-b - sqrt(D)) / (2 * a);
        printf("\n두 개의 서로 다른 실근\n");
        printf("근1: %.2f\n", answer1);
        printf("근2: %.2f\n", answer2);
    }
    else if (D == 0) {
        double answer = -b / (2 * a);
        printf("\n중근: %.2f\n", answer);
    }
    else {
        printf("\n허근을 갖습니다.\n");
    }
}

int main() {
    double a, b, c;

    printf("이차방정식의 계수 a, b, c를 입력하세요.\n");
    printf("a: ");
    scanf_s("%lf", &a);
    printf("b: ");
    scanf_s("%lf", &b);
    printf("c: ");
    scanf_s("%lf", &c);

    solve(a, b, c);

    return 0;
}