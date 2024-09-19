#include <stdio.h>

int factorial(int n);

int main() {
	int num;

	printf("계산할 팩토리얼 값 입력 : ");
	scanf_s("%d", &num);

	int result = factorial(num);
	printf("%d! = %d\n", num, result);

}

int factorial(int n) {
	if (n == 0 || n ==1) {
		return 1;
	}
	int result;
	result = n * factorial(n - 1);

	return result;
}