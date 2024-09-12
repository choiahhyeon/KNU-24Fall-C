#include <stdio.h>

int main() {
	int a; 
	double num1, num2;

	printf("원하는 기능을 입력하시오.\n");
	printf("1.더하기 2.빼기 3.곱하기 4. 나누기\n");
	printf("기능 : ");
	scanf_s("%d", &a);

	printf("숫자 1을 입력하세요 : ");
	scanf_s("%lf", &num1);
	printf("숫자 2를 입력하세요 : ");
	scanf_s("%lf", &num2);

	double result = 0;
	if (a == 1) {
		result = num1 + num2;
	}
	else if (a == 2) {
		result = num1 - num2;
	}
	else if (a == 3) {
		result = num1 * num2;
	}
	else if (a == 4) {
		result = num1 / num2;
	}
	printf("result = %lf", result);

	return 0;
}