#include <stdio.h>

int factorial(int n);

int main() {
	int num;

	printf("����� ���丮�� �� �Է� : ");
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