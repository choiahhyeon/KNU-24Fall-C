#include <stdio.h>

int main() {
	int a; double num1, num2;

	printf("���ϴ� ����� �Է��Ͻÿ�.\n");
	printf("1.���ϱ� 2.���� 3.���ϱ� 4. ������");
	printf("��� : %d", a);
	scanf_s("%d", &a);

	printf("���� 1�� �Է��ϼ��� : %d", num1);
	scanf_s("%lf", &num1);
	printf("���� 2�� �Է��ϼ��� : %d", num2);
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