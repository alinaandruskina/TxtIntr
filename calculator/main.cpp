#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <iomanip>

void print_help() {
    std::cout << "Калькулятор (Вариант 1: аддитивный)\n";
    std::cout << "\n";
    std::cout << "Использование:\n";
    std::cout << "  calc -o <операция> <число1> <число2> [<число3>] [<число4>]\n";
    std::cout << "\n";
    std::cout << "Параметры:\n";
    std::cout << "  -h, --help              Показать эту справку и выйти\n";
    std::cout << "  -o, --operation <оп.>   Тип выполняемой операции (обязательный)\n";
    std::cout << "\n";
    std::cout << "Поддерживаемые операции:\n";
    std::cout << "  summa         Сложение всех чисел\n";
    std::cout << "  subtraction   Вычитание (из первого числа все остальные)\n";
    std::cout << "\n";
    std::cout << "Операнды (позиционные):\n";
    std::cout << "  Числа, от 2 до 4 штук.\n";
    std::cout << "\n";
    std::cout << "Примеры:\n";
    std::cout << "  calc -o summa 45 13 -2\n";
    std::cout << "  calc --operation subtraction 100 20 10\n";
    std::cout << "  calc -h\n";
    std::cout << "\n";
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        print_help();
        return 0;
    }

    std::vector<std::string> args;
    for (int i = 1; i < argc; i++) {
        args.push_back(argv[i]);
    }

    for (const auto &a : args) {
        if (a == "-h" || a == "--help") {
            print_help();
            return 0;
        }
    }

    std::string operation;
    int start_index = -1;

    for (size_t i = 0; i < args.size(); i++) {
        if (args[i] == "-o" || args[i] == "--operation") {
            if (i + 1 < args.size()) {
                operation = args[i + 1];
                start_index = i + 2;
                break;
            } else {
                std::cout << "Ошибка: Не указано название операции.\n";
                return 1;
            }
        }
    }

    if (operation.empty()) {
        std::cout << "Ошибка: Не указана операция (-o или --operation).\n\n";
        print_help();
        return 1;
    }

    int num_count = args.size() - start_index;
    if (num_count < 2 || num_count > 4) {
        std::cout << "Ошибка: Количество операндов должно быть от 2 до 4.\n";
        return 1;
    }

    double result = std::stod(args[start_index]);

    if (operation == "summa") {
        for (int i = start_index + 1; i < (int)args.size(); i++) {
            result += std::stod(args[i]);
        }
        std::cout << "Результат сложения: " << std::fixed << std::setprecision(2) << result << "\n";
    }
    else if (operation == "subtraction") {
        for (int i = start_index + 1; i < (int)args.size(); i++) {
            result -= std::stod(args[i]);
        }
        std::cout << "Результат вычитания: " << std::fixed << std::setprecision(2) << result << "\n";
    }
    else {
        std::cout << "Ошибка: Неизвестная операция.\n\n";
        print_help();
        return 1;
    }

    return 0;
}
