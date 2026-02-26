#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    size_t size = 10 * 1024 * 1024; 
    printf("Спроба виділити %zu байт динамічної пам'яті...\n", size);

    char *ptr = (char *)malloc(size);

    if (ptr == NULL) {
        printf("Помилка: Не вдалося виділити пам'ять! (Обмеження спрацювало)\n");
        return 1;
    } else {
        printf("Пам'ять успішно виділена.\n");
        memset(ptr, 0, size); 
        free(ptr);
    }

    return 0;
}