#include <iostream>
#include <stack>
#include <string>
#include <cmath>

using namespace std;

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

bool isNumeric(char c) {
    return isdigit(c) || c == '.';
}

bool isValidExpression(const string& expression) {
    stack<char> parentheses;
    bool lastWasOperator = true;

    for (char c : expression) {
        if (c == '(') {
            parentheses.push(c);
            lastWasOperator = true;
        } else if (c == ')') {
            if (parentheses.empty()) {
                return false; // Unmatched closing parenthesis
            }
            parentheses.pop();
            lastWasOperator = false;
        } else if (isOperator(c)) {
            if (lastWasOperator) {
                return false; // Two operators in a row
            }
            lastWasOperator = true;
        } else if (isNumeric(c)) {
            lastWasOperator = false;
        } else if (c != ' ') {
            return false; // Invalid character
        }
    }

    return parentheses.empty() && !lastWasOperator;
}

int precedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    } else if (op == '*' || op == '/') {
        return 2;
    }
    return 0;
}

double applyOperator(double a, double b, char op) {
    switch (op) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            return a / b;
        default:
            return 0;
    }
}

double evaluateExpression(const string& expression) {
    if (!isValidExpression(expression)) {
        cout << "Invalid expression" << endl;
        return 0.0;
    }

    stack<double> values;
    stack<char> operators;

    for (size_t i = 0; i < expression.length(); i++) {
        char c = expression[i];

        if (isdigit(c) || c == '.') {
            string number;
            while (i < expression.length() && (isdigit(expression[i]) || expression[i] == '.')) {
                number += expression[i];
                i++;
            }
            values.push(stod(number));
            i--;
        } else if (c == '(') {
            operators.push(c);
        } else if (c == ')') {
            while (!operators.empty() && operators.top() != '(') {
                char op = operators.top();
                operators.pop();
                double b = values.top();
                values.pop();
                double a = values.top();
                values.pop();
                values.push(applyOperator(a, b, op));
            }
            operators.pop();
        } else if (isOperator(c)) {
            while (!operators.empty() && precedence(c) <= precedence(operators.top())) {
                char op = operators.top();
                operators.pop();
                double b = values.top();
                values.pop();
                double a = values.top();
                values.pop();
                values.push(applyOperator(a, b, op));
            }
            operators.push(c);
        }
    }

    while (!operators.empty()) {
        char op = operators.top();
        operators.pop();
        double b = values.top();
        values.pop();
        double a = values.top();
        values.pop();
        values.push(applyOperator(a, b, op));
    }

    return values.top();
}

int main() {
    string expression;
    while (true) {
        getline(cin, expression);
        if (expression == "q")
            return 0;
        string result;
        for (char c : expression) {
            if (c != ' ' && c != '\n') {
                result += c;
            }
        }
        expression = result;
        cout << "表达式为：" << expression << endl;
        if (isValidExpression(expression)) {
            double result = evaluateExpression(expression);
            if(isinf(result)) 
              cout<<"Division by zero"<<endl;
            else
              cout << "表达式结果：" << result << endl;
        } else {
            cout << "Invalid expression" << endl;
        }
    }

    return 0;
}
