#include <stdio.h>

int prime_number(int num);

int main() {
	int num;

	printf("소수인지 확인할 수를 입력하세요 : ");
	scanf_s("%d", &num);

	if (prime_number(num)) {
		printf("해당 수는 소수입니다. (return = 1)");
	}
	else {
		printf("해당 수는 소수가 아닙니다. (return = 0)");
	}
	return 0;
}

int prime_number(int num) {
	if (num < 2) {
		return 0;
	}

	for (int i = 2; i * i <= num; i++) {
		if (num % i == 0) {
			return 0;
		}
	}
	return 1; 
}