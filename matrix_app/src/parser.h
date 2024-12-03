#ifndef PARSER_H
#define PARSER_H

#include<iostream>
#include<stack>
#include <vector>
//std::vector<std::stack<QString>> process_the_expression(QString expression){
#include <iostream>
#include <stack>
#include <vector>
#include <QString>
#include <QStringList>
#include <map>
#include <unordered_map>

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

    // std::unordered_map<QString, int> num_collection = {
    //     {"0", 1}, {"1", 1}, {"2", 1}, {"3", 1}, {"4", 1},
    //     {"5", 1}, {"6", 1}, {"7", 1}, {"8", 1}, {"9", 1}
    // };



    for (const QString& token : tokens) {
        if (token.startsWith("M"))  {
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



#endif
