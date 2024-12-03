#include <iostream>
#include <stack>
#include <vector>
#include <QString>
#include <QStringList>
#include <map>

// Функция возвращает приоритет операции
int get_priority(const QString& op) {
    if (op == "det") return 3; // Самый высокий приоритет
    if (op == "*") return 2;  // Умножение
    if (op == "+") return 1;  // Сложение
    return 0; // Для неизвестных или низкоприоритетных
}

// Функция проверки, является ли строка оператором
bool is_operator(const QString& token) {
    return token == "+" || token == "*" || token == "det";
}

// Функция преобразования выражения в польскую нотацию
std::vector<QString> process_the_expression(const QString& expression) {
    std::vector<QString> output; // Результат (постфиксная нотация)
    std::stack<QString> operators; // Стек операторов
    QStringList tokens = expression.split(" ", Qt::SkipEmptyParts); // Разделяем строку на токены

    for (const QString& token : tokens) {
        if (token.startsWith("a")) {
            // Если токен — переменная (например, a1, a2), добавляем в результат
            output.push_back(token);
        } else if (is_operator(token)) {
            // Если токен — оператор
            while (!operators.empty() &&
                get_priority(operators.top()) >= get_priority(token)) {
                output.push_back(operators.top());
            operators.pop();
                }
                operators.push(token);
        } else if (token == "(") {
            // Если токен — открывающая скобка
            operators.push(token);
        } else if (token == ")") {
            // Если токен — закрывающая скобка
            while (!operators.empty() && operators.top() != "(") {
                output.push_back(operators.top());
                operators.pop();
            }
            if (!operators.empty() && operators.top() == "(") {
                operators.pop(); // Удаляем открывающую скобку
            }
        }
    }

    // После обработки всех токенов, переносим оставшиеся операторы
    while (!operators.empty()) {
        output.push_back(operators.top());
        operators.pop();
    }

    return output;
}

int main() {
    QString expression = "a1 + a2 + a1  * a2 * 2 + det ( a1 ) * a2";
    auto result = process_the_expression(expression);

    std::cout << "Postfix notation: ";
    for (const QString& token : result) {
        std::cout << token.toStdString() << " ";
    }
    std::cout << std::endl;

    return 0;
}
