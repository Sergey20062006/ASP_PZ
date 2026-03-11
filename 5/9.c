#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Помилка: Не вказано аргументів\n");
        return 1;
    }

    if (argc > 2) {
        printf("Помилка: Занадто багато аргументів\n");
        return 1;
    }

    char *ptr = malloc(32);
    strcpy(ptr, "буфер");

    if (strchr(argv[1], 'a')) {
        printf("ptr містить 'a': Звільняю пам'ять...\n");
        free(ptr);
    }

    if (strchr(argv[1], 'b')) {
        printf("ptr містить 'b': Звільняю пам'ять...\n");
        free(ptr);
    }

    return 0;
}