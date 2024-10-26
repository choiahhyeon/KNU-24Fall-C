#include <stdio.h>
#include <stdlib.h>

struct Product {
	int id;
	char name[100];
	int price;
};

void printProduct(struct Product product) {
	printf("상품 ID : %d\n", product.id);
	printf("상품명 : %s\n", product.name);
	printf("가격 : %d원\n", product.price);
	printf("\n");
}

int main() {
	struct Product product[5];
	int i;

	for (i = 0; i < 5; i++) {
		printf("상품정보를 입력하세요 (입력 중단은 id에 0 입력)\n");

		printf("상품id : ");
		scanf_s("%d", &product[i].id);

		if (product[i].id == 0) {
			break;
		}

		printf("상품명 : ");
		scanf_s("%s", product[i].name, sizeof(product[i].name));

		printf("상품 가격 : ");
		scanf_s("%d", &product[i].price);
		printf("\n");
	}

	printf("<<입력된 상품 목록>>\n");

	for (int j = 0; j < i; j++) {
		printProduct(product[j]);
	}

	return 0;
}