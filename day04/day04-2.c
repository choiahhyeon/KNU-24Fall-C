#include <stdio.h>

void swap(int* pa, int* pb) {
	int temp;
	temp = *pa;
	*pa = *pb;
	*pb = temp;
}

int main() {
	int a = 10;
	int b = 20;
	printf("�Լ� ȣ�� ��: a = %d b = %d\n", a, b);
	swap(&a, &b);
	printf("�Լ� ȣ�� ��: a = %d b = %d\n", a, b);
	return 0;
}