#include <stdio.h>

int main() {
	int a; 
	double num1, num2;

	printf("���ϴ� ����� �Է��Ͻÿ�.\n");
	printf("1.���ϱ� 2.���� 3.���ϱ� 4. ������\n");
	printf("��� : ");
	scanf_s("%d", &a);

	printf("���� 1�� �Է��ϼ��� : ");
	scanf_s("%lf", &num1);
	printf("���� 2�� �Է��ϼ��� : ");
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