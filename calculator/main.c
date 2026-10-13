#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_help(void) {
    printf("Калькулятор (Вариант 1: аддитивный)\n");
    printf("\n");
    printf("Использование:\n");
    printf("  calc -o <операция> <число1> <число2> [<число3>] [<число4>]\n");
    printf("\n");
    printf("Параметры:\n");
    printf("  -h, --help              Показать эту справку и выйти\n");
    printf("  -o, --operation <оп.>   Тип выполняемой операции (обязательный)\n");
    printf("\n");
    printf("Поддерживаемые операции:\n");
    printf("  summa         Сложение всех чисел\n");
    printf("  subtraction   Вычитание (из первого числа все остальные)\n");
    printf("\n");
    printf("Операнды (позиционные):\n");
    printf("  Числа, от 2 до 4 штук. Могут быть отрицательными и дробными.\n");
    printf("\n");
    printf("Примеры:\n");
    printf("  calc -o summa 45 13 -2\n");
    printf("  calc --operation subtraction 100 20 10\n");
    printf("  calc -h\n");
    printf("\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        print_help();
        return 0;
    }

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0) {
            print_help();
            return 0;
        }
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
                printf("Ошибка: Не указано название операции.\n");
                return 1;
            }
        }
    }

    if (operation == NULL) {
        printf("Ошибка: Не указана операция (-o или --operation).\n\n");
        print_help();
        return 1;
    }

    int num_count = argc - start_index;
    if (num_count < 2 || num_count > 4) {
        printf("Ошибка: Количество операндов должно быть от 2 до 4.\n");
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
        printf("Ошибка: Неизвестная операция.\n\n");
        print_help();
        return 1;
    }

    return 0;
}
