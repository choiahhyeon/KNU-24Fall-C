#include <stdio.h>
#include <math.h>

void solve(int a, int b, int c) {
    double D = (double)b * b - 4 * a * c;

    if (D < 0) {
        printf("\n허근을 갖습니다.\n");
    }
    else if (D == 0) {
        double answer = -b / (2.0 * a);
        printf("\n중근: %.2f\n", answer);
    }
    else {
        double answer1 = (-b + sqrt(D)) / (2.0 * a);
        double answer2 = (-b - sqrt(D)) / (2.0 * a);
        printf("\n두 개의 서로 다른 실근:\n");
        printf("근1: %.2f\n", answer1);
        printf("근2: %.2f\n", answer2);
    }
}

int main() {
    int a, b, c;

    printf("이차방정식의 계수 a, b, c를 입력하세요.\n");
    printf("a: ");
    scanf_s("%d", &a);
    printf("b: ");
    scanf_s("%d", &b);
    printf("c: ");
    scanf_s("%d", &c);

    solve(a, b, c);

    return 0;
}