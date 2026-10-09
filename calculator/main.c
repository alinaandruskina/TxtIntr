#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_help(const char *program_name) {
    printf("Использование: %s -o <операция> <число1> <число2> ...\n", program_name);
    printf("Операции:\n");
    printf("  summa        - Сложение всех чисел\n");
    printf("  subtraction  - Вычитание (из первого числа все остальные)\n");
    printf("Пример: %s -o summa 45 13 -2\n", program_name);
}

int main(int argc, char *argv[]) {
    if (argc < 2 || strcmp(argv[1], "--help") == 0 || strcmp(argv[1], "-h") == 0) {
        print_help(argv[0]);
        return 0;
    }

    char *operation = NULL;
    int start_index = -1;

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-o") == 0 || strcmp(argv[i], "--operation") == 0) {
            if (i + 1 < argc) {
                operation = argv[i + 1];
                start_index = i + 2;
                break;
            } else {
                printf("Ошибка: Не указано название операции\n");
                return 1;
            }
        }
    }

    if (operation == NULL) {
        printf("Ошибка: Не указана операция (-o или --operation).\n");
        print_help(argv[0]);
        return 1;
    }

    int num_count = argc - start_index;
    if (num_count < 2 || num_count > 4) {
        printf("Ошибка: Количество операндов должно быть от 2 до 4. Вы ввели: %d\n", num_count);
        return 1;
    }

    double result = atof(argv[start_index]);

    if (strcmp(operation, "summa") == 0) {
        for (int i = start_index + 1; i < argc; i++) {
            result += atof(argv[i]);
        }
        printf("Результат сложения: %.2f\n", result);
    }
    else if (strcmp(operation, "subtraction") == 0) {
        for (int i = start_index + 1; i < argc; i++) {
            result -= atof(argv[i]);
        }
        printf("Результат вычитания: %.2f\n", result);
    }
    else {
        printf("Ошибка: Неизвестная операция '%s'.\n", operation);
        print_help(argv[0]);
        return 1;
    }

    return 0;
}
