#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main() {
    double x = 0;
    double y = 0;
    int circle = 0;
    long long iteration = 1000000000;
    long long print_interval = 10000000;

    srand(time(NULL));

    for (long long i = 0; i < iteration; i++) {
        x = (double)rand() / RAND_MAX;
        y = (double)rand() / RAND_MAX; 

 
        if (sqrt(x * x + y * y) <= 1) {
            circle++;
        }

        if (i % print_interval == 0) {
            double estimate = 4.0 * circle / (i + 1);
            double progress = (double)(i + 1) / iteration * 100.0;
            printf("%.0f%% 진행.. 원주율: %f ", progress, estimate);

            int box = (int)(progress / 5);
            for (int j = 0; j < box && j < 20; j++) {
                printf("■"); 
            }
            for (int j = 0; j < 20 - box && j < 20; j++) {
                printf("□");
            }
            printf("\n");
        }
    }

    double pi = 4.0 * circle / iteration;
    printf("원주율: %f\n", pi);

    return 0;
}
