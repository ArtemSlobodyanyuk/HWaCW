#include <iostream>
#include <stack>
#include <sstream>
#include <string>
#include <stdexcept>

int evaluateRPN(const std::string& expression) {
    std::stack<int> stack;
    std::stringstream ss(expression);
    std::string token;

    while (ss >> token) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            if (stack.size() < 2) {
                throw std::invalid_argument("Недостатньо операндів для виконання операції.");
            }

            int b = stack.top(); stack.pop();
            int a = stack.top(); stack.pop();

            if (token == "+") {
                stack.push(a + b);
            } else if (token == "-") {
                stack.push(a - b);
            } else if (token == "*") {
                stack.push(a * b);
            } else if (token == "/") {
                if (b == 0) {
                    throw std::runtime_error("Ділення на нуль.");
                }
                stack.push(a / b);
            }
        } else {
            try {
                stack.push(std::stoi(token));
            } catch (const std::exception&) {
                throw std::invalid_argument("Некоректний операнд: " + token);
            }
        }
    }

    if (stack.size() != 1) {
        throw std::invalid_argument("Некоректний вираз.");
    }

    return stack.top();
}

int main() {
    std::string input;

    std::cout << "Введіть вираз у ЗПН: ";
    std::getline(std::cin, input);

    try {
        int result = evaluateRPN(input);
        std::cout << "Результат: " << result << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Помилка: " << e.what() << std::endl;
    }

    return 0;
}
