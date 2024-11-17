#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct NODE {
    char name[50];
    int score;
    struct NODE* link;
};

struct NODE* head = NULL;

struct NODE* create_node(char* name, int score) {
    struct NODE* new_node = (struct NODE*)malloc(sizeof(struct NODE));
    if (new_node == NULL) {
        return NULL;
    }
    strcpy_s(new_node->name, sizeof(new_node->name), name);
    new_node->score = score;
    new_node->link = NULL;

    return new_node;
}

struct NODE* last_node() {
    struct NODE* cur = head;
    while (cur != NULL && cur->link != NULL) {
        cur = cur->link;
    }
    return cur;
}

void insert_node_last(char* name, int score) {
    struct NODE* new_node = create_node(name, score);
    if (new_node == NULL) return;

    if (head == NULL) {
        head = new_node;
    }
    else {
        struct NODE* last = last_node();
        last->link = new_node;
    }
}

void print_nodes() {
    struct NODE* cur = head;
    if (cur == NULL) {
        printf("�л� ����� ��� �ֽ��ϴ�.\n");
        return;
    }
    printf("----------------------------\n");
    while (cur != NULL) {
        printf("%s : %d\n", cur->name, cur->score);
        cur = cur->link;
    }
    printf("----------------------------\n");
}

struct NODE* find_node(char* name) {
    struct NODE* cur = head;
    while (cur != NULL) {
        if (strcmp(cur->name, name) == 0) return cur;
        cur = cur->link;
    }
    return NULL;
}

int delete_node(char* name) {
    struct NODE* prev = NULL;
    struct NODE* cur = head;

    while (cur != NULL) {
        if (strcmp(cur->name, name) == 0) {
            if (prev == NULL) {
                head = cur->link;
            }
            else {
                prev->link = cur->link;
            }
            free(cur);
            return 1;
        }
        prev = cur;
        cur = cur->link;
    }
    return 0;
}

void sort_nodes() {
    if (head == NULL || head->link == NULL) return;

    struct NODE* current;
    struct NODE* next;
    char tempName[50];
    int tempScore;

    for (current = head; current->link != NULL; current = current->link) {
        for (next = current->link; next != NULL; next = next->link) {
            if (current->score < next->score) {
                strcpy_s(tempName, sizeof(tempName), current->name);
                strcpy_s(current->name, sizeof(current->name), next->name);
                strcpy_s(next->name, sizeof(next->name), tempName);

                tempScore = current->score;
                current->score = next->score;
                next->score = tempScore;
            }
        }
    }
}

int main() {
    int choice;
    char name[50];
    int score;

    while (1) {
        printf("1. �л��� ������ �Է�\n2. �л� ���� ����\n3. ���α׷� ����\n");
        printf("input : ");

        if (scanf_s("%d", &choice) != 1) {
            printf("�߸��� �Է��Դϴ�. ���ڸ� �Է��ϼ���.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
        case 1:
            printf("�л� �̸�: ");
            scanf_s("%s", name, sizeof(name));
            printf("%s�� ����: ", name);
            scanf_s("%d", &score);
            insert_node_last(name, score);
            sort_nodes();
            print_nodes();
            break;
        case 2:
            printf("������ �л� �̸�: ");
            scanf_s("%s", name, sizeof(name));
            if (delete_node(name)) {
                printf("�л� %s�� �����Ǿ����ϴ�.\n", name);
            }
            else {
                printf("�л� %s�� ã�� �� �����ϴ�.\n", name);
            }
            print_nodes();
            break;
        case 3:
            printf("���α׷��� �����մϴ�.\n");
            return 0;
        default:
            printf("�߸��� �����Դϴ�. �ٽ� �õ��ϼ���.\n");
        }
    }

    return 0;
}