#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum rank { RANK_1 = 1, RANK_2, RANK_3 };

struct Customer {
    char* customerName;
    enum rank rank;
    int order_amount;
    int point;
    struct Customer* prev;
    struct Customer* next;
};

struct Customer* head = NULL;

int compare_customers(struct Customer* a, struct Customer* b) {
    if (a->rank != b->rank) return a->rank - b->rank;
    if (a->order_amount != b->order_amount) return b->order_amount - a->order_amount;
    return b->point - a->point;
}

void insert_customer(const char* name, enum rank rank, int order_amount, int point) {
    struct Customer* newCustomer = (struct Customer*)malloc(sizeof(struct Customer));
    if (newCustomer == NULL) {
        printf("�޸� �Ҵ� ����\n");
        return;
    }
    newCustomer->customerName = _strdup(name);
    newCustomer->rank = rank;
    newCustomer->order_amount = order_amount;
    newCustomer->point = point;
    newCustomer->prev = newCustomer->next = NULL;

    struct Customer* current = head;
    while (current && compare_customers(current, newCustomer) < 0) {
        current = current->next;
    }

    if (!current) {
        if (head) {
            struct Customer* last = head;
            while (last->next) last = last->next;
            last->next = newCustomer;
            newCustomer->prev = last;
        }
        else {
            head = newCustomer;
        }
    }
    else {
        if (current->prev) current->prev->next = newCustomer;
        else head = newCustomer;
        newCustomer->prev = current->prev;
        newCustomer->next = current;
        current->prev = newCustomer;
    }
    printf("%s ���� �߰��Ǿ����ϴ�.\n", name);
}

void delete_customer(const char* name) {
    struct Customer* current = head;
    while (current && strcmp(current->customerName, name) != 0) {
        current = current->next;
    }

    if (!current) {
        printf("�� %s�� ã�� �� �����ϴ�.\n", name);
        return;
    }

    if (current->prev) current->prev->next = current->next;
    else head = current->next;
    if (current->next) current->next->prev = current->prev;

    free(current->customerName);
    free(current);
    printf("�� %s�� �����Ǿ����ϴ�.\n", name);
}

void update_customer(const char* name, enum rank rank, int order_amount, int point) {
    delete_customer(name);
    insert_customer(name, rank, order_amount, point);
    printf("�� %s�� ������ �����Ǿ����ϴ�.\n", name);
}

void print_customers() {
    printf("----------------------------\n");
    printf("�� ���:\n");
    struct Customer* current = head;
    while (current) {
        printf("�̸�: %s, ���: %d, �ֹ���: %d, ����Ʈ: %d\n",
            current->customerName, current->rank, current->order_amount, current->point);
        current = current->next;
    }
    printf("----------------------------\n");
}

void free_customers() {
    struct Customer* current = head;
    while (current) {
        struct Customer* next = current->next;
        free(current->customerName);
        free(current);
        current = next;
    }
}

int main() {
    int choice;
    char name[50];
    int customerRank, order_amount, point;

    while (1) {
        print_customers();

        printf("1. �� �߰�\n2. �� ����\n3. �� ����\n4. ����\n");
        printf("input : ");
        scanf_s("%d", &choice);

        if (choice == 1) {
            printf("�� �̸�: ");
            scanf_s("%s", name, (unsigned int)sizeof(name));
            printf("�� ��� (1~3): ");
            scanf_s("%d", &customerRank);
            printf("�ֹ���: ");
            scanf_s("%d", &order_amount);
            printf("����Ʈ: ");
            scanf_s("%d", &point);
            insert_customer(name, (enum rank)customerRank, order_amount, point);
        }
        else if (choice == 2) {
            printf("������ �� �̸�: ");
            scanf_s("%s", name, (unsigned int)sizeof(name));
            delete_customer(name);
        }
        else if (choice == 3) {
            printf("������ �� �̸�: ");
            scanf_s("%s", name, (unsigned int)sizeof(name));
            printf("�� ��� (1~3): ");
            scanf_s("%d", &customerRank);
            printf("�� �ֹ���: ");
            scanf_s("%d", &order_amount);
            printf("�� ����Ʈ: ");
            scanf_s("%d", &point);
            update_customer(name, (enum rank)customerRank, order_amount, point);
        }
        else if (choice == 4) {
            free_customers();
            printf("���α׷��� �����մϴ�.\n");
            break;
        }
        else {
            printf("�߸��� �����Դϴ�. �ٽ� �õ��ϼ���.\n");
        }
    }
    return 0;
}