#include <iostream>

using namespace std;

const int MAX_SIZE = 100;

int getPriority(char op) {
    if (op == '!') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '!' || c == '(' || c == ')';
}

int factorial(int n) {
    if (n < 0) throw runtime_error("Факторіал не визначений для від'ємних чисел.");
    int result = 1;
    for (int i = 1; i <= n; ++i) result *= i;
    return result;
}

void toRPN(char infix[], char rpn[]) {
    char stack[MAX_SIZE];
    int stackTop = -1, rpnIndex = 0;

    for (int i = 0; infix[i] != '\0'; ++i) {
        char c = infix[i];

        if (c >= '0' && c <= '9') {
            rpn[rpnIndex++] = c;
            if (infix[i + 1] < '0' || infix[i + 1] > '9') rpn[rpnIndex++] = ' ';
        } else if (c == '(') {
            stack[++stackTop] = c;
        } else if (c == ')') {
            while (stackTop >= 0 && stack[stackTop] != '(') {
                rpn[rpnIndex++] = stack[stackTop--];
            }
            if (stackTop >= 0 && stack[stackTop] == '(') stackTop--;
        } else if (isOperator(c)) {
            while (stackTop >= 0 && getPriority(stack[stackTop]) >= getPriority(c) && stack[stackTop] != '(') {
                rpn[rpnIndex++] = stack[stackTop--];
            }
            stack[++stackTop] = c;
        }
    }

    while (stackTop >= 0) {
        rpn[rpnIndex++] = stack[stackTop--];
    }

    rpn[rpnIndex] = '\0'; 
}

double evaluateRPN(char rpn[]) {
    double stack[MAX_SIZE];
    int stackTop = -1;

    for (int i = 0; rpn[i] != '\0'; ++i) {
        char c = rpn[i];

        if (c >= '0' && c <= '9') {
            double number = 0;
            while (c >= '0' && c <= '9') {
                number = number * 10 + (c - '0');
                c = rpn[++i];
            }
            stack[++stackTop] = number;
        } else if (isOperator(c)) {
            if (c == '!') {
                int operand = (int)stack[stackTop--];
                stack[++stackTop] = factorial(operand);
            } else {
                double b = stack[stackTop--];
                double a = stack[stackTop--];
                double result = 0;

                switch (c) {
                    case '+': result = a + b; break;
                    case '-': result = a - b; break;
                    case '*': result = a * b; break;
                    case '/': 
                        if (b == 0) throw runtime_error("Ділення на нуль.");
                        result = a / b; 
                        break;
                }
                stack[++stackTop] = result;
            }
        }
    }

    return stack[stackTop];
}

int main() {
    char input[MAX_SIZE], rpn[MAX_SIZE];

    cout << "Введіть математичний вираз: ";
    cin.getline(input, MAX_SIZE);

    try {
        toRPN(input, rpn);
        cout << "Зворотна польська нотація: " << rpn << endl;

        double result = evaluateRPN(rpn);
        cout << "Результат: " << result << endl;
    } catch (const exception& e) {
        cerr << "Помилка: " << e.what() << endl;
    }

    return 0;
}
