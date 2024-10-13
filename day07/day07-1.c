#include <stdio.h>

int main() {
    int Num;
    printf("층을 입력하세요: ");
    scanf_s("%d", &Num);

    printf("%d층 피라미드\n", Num);

    for (int i = 1; i <= Num; i++) {
        for (int j = 1; j <= Num - i; j++) {
            printf(" ");
        }
        for (int k = 1; k <= 2 * i - 1; k++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}