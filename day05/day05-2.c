#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
	int snum;
	char name[100]; //char* name;
	int score;
};

int main() {
	int N;
	struct Student *person;

	printf("�л� �� �Է�: ");
	scanf_s("%d", &N);

	person = (struct Student*)malloc(N * sizeof(struct Student));
	//for(int i = 0; i < N; i++) person[i].name = (char*)malloc(sizeof(char) * 50);

	for (int i = 0; i < N; i++) {
		printf("�й�: ");
		scanf_s("%d", &person[i].snum);
		printf("�̸�: ");
		scanf_s("%s", person[i].name, 100);
		printf("����: ");
		scanf_s("%d", &person[i].score);
	}

	free(person);

	return 0;
}