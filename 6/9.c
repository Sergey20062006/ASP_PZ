#include <stdio.h>
#include <stdlib.h>

int main() {
    int stack_var;
    void *heap_var = malloc(10);

    printf("Стек:      %p\n", (void*)&stack_var);
    printf("Купа:      %p\n", heap_var);
    printf("Бібліотека: %p\n", (void*)&printf);

    free(heap_var);
    return 0;
}