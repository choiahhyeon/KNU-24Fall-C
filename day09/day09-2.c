#include <stdio.h>
#include <stdlib.h>

struct Product {
	int id;
	char name[100];
	int price;
};

void printProduct(struct Product product) {
	printf("��ǰ ID : %d\n", product.id);
	printf("��ǰ�� : %s\n", product.name);
	printf("���� : %d��\n", product.price);
	printf("\n");
}

int main() {
	struct Product product[5];
	int i;

	for (i = 0; i < 5; i++) {
		printf("��ǰ������ �Է��ϼ��� (�Է� �ߴ��� id�� 0 �Է�)\n");

		printf("��ǰid : ");
		scanf_s("%d", &product[i].id);

		if (product[i].id == 0) {
			break;
		}

		printf("��ǰ�� : ");
		scanf_s("%s", product[i].name, sizeof(product[i].name));

		printf("��ǰ ���� : ");
		scanf_s("%d", &product[i].price);
		printf("\n");
	}

	printf("<<�Էµ� ��ǰ ���>>\n");

	for (int j = 0; j < i; j++) {
		printProduct(product[j]);
	}

	return 0;
}