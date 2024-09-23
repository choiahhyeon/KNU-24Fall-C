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
	printf("함수 호출 전: a = %d b = %d\n", a, b);
	swap(&a, &b);
	printf("함수 호출 후: a = %d b = %d\n", a, b);
	return 0;
}