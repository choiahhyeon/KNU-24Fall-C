#include <stdio.h>

int prime_number(int num);

int main() {
	int num;

	printf("�Ҽ����� Ȯ���� ���� �Է��ϼ��� : ");
	scanf_s("%d", &num);

	if (prime_number(num)) {
		printf("�ش� ���� �Ҽ��Դϴ�. (return = 1)");
	}
	else {
		printf("�ش� ���� �Ҽ��� �ƴմϴ�. (return = 0)");
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