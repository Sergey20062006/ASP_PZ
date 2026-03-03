#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ITEMS 1000000
#define ITEM_SIZE 64 

int main() {
    clock_t start, end;

    printf("Тест 1: Стандартний malloc\n");
    start = clock();
    for (int i = 0; i < ITEMS; i++) {
        void *p = malloc(ITEM_SIZE); 
        free(p); 
    }
    end = clock();
    printf("Стандартний malloc: %f сек.\n", (double)(end - start) / CLOCKS_PER_SEC);

    printf("\nТест 2: Memory Pool\n");
    char *big_block = malloc(ITEMS * ITEM_SIZE); 
    char *current_pos = big_block;

    start = clock();
    for (int i = 0; i < ITEMS; i++) {
        void *p = current_pos;
        current_pos += ITEM_SIZE;
    }
    end = clock();
    printf("Memory Pool:     %f сек.\n", (double)(end - start) / CLOCKS_PER_SEC);

    free(big_block);
    return 0;
}