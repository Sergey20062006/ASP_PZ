#include <stdio.h>

int global = 100;

int main() {
    int stack = 10;
    printf("Адреса stack (Stack):    %p\n", (void*)&stack);
    printf("Адреса printf (Library): %p\n", (void*)printf);
    printf("Адреса global (Data):    %p\n", (void*)&global);

    return 0;
}