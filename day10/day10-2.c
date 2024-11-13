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
        printf("메모리 할당 실패\n");
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
    printf("%s 고객이 추가되었습니다.\n", name);
}

void delete_customer(const char* name) {
    struct Customer* current = head;
    while (current && strcmp(current->customerName, name) != 0) {
        current = current->next;
    }

    if (!current) {
        printf("고객 %s를 찾을 수 없습니다.\n", name);
        return;
    }

    if (current->prev) current->prev->next = current->next;
    else head = current->next;
    if (current->next) current->next->prev = current->prev;

    free(current->customerName);
    free(current);
    printf("고객 %s가 삭제되었습니다.\n", name);
}

void update_customer(const char* name, enum rank rank, int order_amount, int point) {
    delete_customer(name);
    insert_customer(name, rank, order_amount, point);
    printf("고객 %s의 정보가 수정되었습니다.\n", name);
}

void print_customers() {
    printf("----------------------------\n");
    printf("고객 목록:\n");
    struct Customer* current = head;
    while (current) {
        printf("이름: %s, 등급: %d, 주문량: %d, 포인트: %d\n",
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

        printf("1. 고객 추가\n2. 고객 삭제\n3. 고객 수정\n4. 종료\n");
        printf("input : ");
        scanf_s("%d", &choice);

        if (choice == 1) {
            printf("고객 이름: ");
            scanf_s("%s", name, (unsigned int)sizeof(name));
            printf("고객 등급 (1~3): ");
            scanf_s("%d", &customerRank);
            printf("주문량: ");
            scanf_s("%d", &order_amount);
            printf("포인트: ");
            scanf_s("%d", &point);
            insert_customer(name, (enum rank)customerRank, order_amount, point);
        }
        else if (choice == 2) {
            printf("삭제할 고객 이름: ");
            scanf_s("%s", name, (unsigned int)sizeof(name));
            delete_customer(name);
        }
        else if (choice == 3) {
            printf("수정할 고객 이름: ");
            scanf_s("%s", name, (unsigned int)sizeof(name));
            printf("새 등급 (1~3): ");
            scanf_s("%d", &customerRank);
            printf("새 주문량: ");
            scanf_s("%d", &order_amount);
            printf("새 포인트: ");
            scanf_s("%d", &point);
            update_customer(name, (enum rank)customerRank, order_amount, point);
        }
        else if (choice == 4) {
            free_customers();
            printf("프로그램을 종료합니다.\n");
            break;
        }
        else {
            printf("잘못된 선택입니다. 다시 시도하세요.\n");
        }
    }
    return 0;
}