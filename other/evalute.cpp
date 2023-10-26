#include <iostream>
#include <stack>
#include <string>
#include <cmath>

using namespace std;

int precedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    } else if (op == '*' || op == '/') {
        return 2;
    } else if (op == '^') {
        return 3;
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
        case '^':
            return pow(a, b);
        default:
            return 0;
    }
}

double evaluateExpression(const string& expression) {
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
        } else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
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
    string expression = "78*(2^5-8)";
    cin>>expression;
    double result = evaluateExpression(expression);
    cout << "表达式结果：" << result << endl;
    return 0;
}

