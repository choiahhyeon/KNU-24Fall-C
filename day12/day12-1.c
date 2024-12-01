#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// topping_len은 배열 topping의 길이입니다.
int solution(int topping[], size_t topping_len) {
    int totalCount[10001] = { 0 };
    int leftCount[10001] = { 0 };
    int totalUnique = 0, leftUnique = 0, ways = 0;

    for (size_t i = 0; i < topping_len; i++) {
        if (totalCount[topping[i]] == 0) {
            totalUnique++;
        }
        totalCount[topping[i]]++;
    }

    for (size_t i = 0; i < topping_len; i++) {
        if (leftCount[topping[i]] == 0) {
            leftUnique++;
        }
        leftCount[topping[i]]++;

        totalCount[topping[i]]--;
        if (totalCount[topping[i]] == 0) {
            totalUnique--;
        }

        if (leftUnique == totalUnique) {
            ways++;
        }
    }

    return ways;
}

int main() {
    int topping1[] = { 1, 2, 1, 3, 1, 4, 1, 2 };
    size_t size1 = sizeof(topping1) / sizeof(topping1[0]);

    int topping2[] = { 1, 2, 3, 1, 4 };
    size_t size2 = sizeof(topping2) / sizeof(topping2[0]);

    printf("topping\tresult\n");
    printf("[1, 2, 1, 3, 1, 4, 1, 2]\t%d\n", solution(topping1, size1));
    printf("[1, 2, 3, 1, 4]\t%d\n", solution(topping2, size2));

    return 0;
}