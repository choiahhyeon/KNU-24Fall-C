#include <stdio.h>

int main() {
	int a; double num1, num2;

	printf("원하는 기능을 입력하시오.\n");
	printf("1.더하기 2.빼기 3.곱하기 4. 나누기");
	printf("기능 : %d", a);
	scanf_s("%d", &a);

	printf("숫자 1을 입력하세요 : %d", num1);
	scanf_s("%lf", &num1);
	printf("숫자 2를 입력하세요 : %d", num2);
	scanf_s("%lf", &num2);

	double result = 0;
	if (a == 1) {
		result = num1 + num2;
	}
	else if (a == 2) {
		result = num1 - num2;
	}
	else if (a==3)

	return 0;
}