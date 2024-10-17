#include <stdio.h>
#include <string.h>

void reverse(char* pnum1, char* pnum2) {
    char temp = *pnum1;
    *pnum1 = *pnum2;
    *pnum2 = temp;
}

int main() {
    char str[100];

    printf("문자열을 입력하세요: ");
    scanf_s("%s", str, sizeof(str));
    
    int count = strlen(str);

    for (int i = 0; i < count / 2; i++) {
        reverse(&str[i], &str[count - 1 - i]);
    }

    printf("뒤집힌 문자열: %s\n", str);

    return 0;
}