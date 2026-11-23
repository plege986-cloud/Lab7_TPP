
#include <iostream>
#include <stdexcept>

// Антипаттерн: исключение перехватывается и скрывается
double badDivide(double a, double b)
{
    try {
        if (b == 0.0) {
            throw std::runtime_error("Division by zero");
        }

        return a / b;
    }
    catch (...) {
        // Ошибка скрывается
        return 0.0;
    }
}

// Правильный вариант: исключение передаётся вызывающему коду
double goodDivide(double a, double b)
{
    if (b == 0.0) {
        throw std::runtime_error("Division by zero");
    }

    return a / b;
}

int main()
{
    std::cout << "=== ANTIPATTERN ===\n";
    std::cout << "Result: " << badDivide(10, 0) << '\n';

    std::cout << "\n=== CORRECT APPROACH ===\n";

    try {
        std::cout << "Result: " << goodDivide(10, 0) << '\n';
    }
    catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << '\n';
    }

    return 0;
}
