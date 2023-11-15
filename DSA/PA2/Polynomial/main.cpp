#include <iostream>
using namespace std;

const int M = 1000000007;

struct Num {
    int nums[65];
    int h;

    Num() {
        h = 0;
        fill(nums, nums + 65, 0);
    }

    Num(int inputNums[65], int inputH) : h(inputH) {
        for (int i = 0; i < 65; ++i) {
            nums[i] = inputNums[i];
            if (nums[i] >= M)
                nums[i] %= M;
        }
        while (nums[h] == 0 && h) {
            h--;
        }
    }

    Num& operator+=(const Num& other) {
        h = max(h, other.h);
        for (int i = 0; i <= h; i++) {
            nums[i] += other.nums[i];
            nums[i] %= M;
        }
        while (nums[h] == 0 && h) {
            h--;
        }
        return *this;
    }

    Num& operator-=(const Num& other) {
        h = max(h, other.h);
        for (int i = 0; i <= h; i++) {
            nums[i] -= other.nums[i];
            nums[i] %= M;
        }
        while (nums[h] == 0 && h) {
            h--;
        }
        return *this;
    }

    Num& operator*=(const Num& other) {
        int tmp[65] = { 0 };
        for (int i = 0; i <= h; i++)
            for (int j = 0; j <= other.h; j++) {
                long long t = (long long)nums[i] * (long long)other.nums[j];
                t %= M;
                tmp[i + j] += t;
                tmp[i + j] %= M;
            }
        h += other.h;
        for (int i = 0; i <= h; i++)
            nums[i] = tmp[i];
        return *this;
    }

    Num& operator^=(int k) {
        if (k > 1) {
            int ans[65] = { 0 };
            int tmp[65] = { 0 };
            int tmph = h;
            for (int i = 0; i <= h; i++)
                tmp[i] = nums[i];
            for (int i = 1; i < k; i++) {
                for (int m = 0; m <= h; m++)
                    for (int n = 0; n <= tmph; n++) {
                        long long t = (long long)nums[m] * (long long)tmp[n];
                        t %= M;
                        ans[m + n] += t;
                        ans[m + n] %= M;
                    }
                h += tmph;
                for (int j = 0; j <= h; j++) {
                    nums[j] = ans[j];
                    ans[j] = 0;
                }
            }
        }
        return *this;
    }

    Num& calculate(const Num& other, char op) {
        switch (op) {
            case '+':
                return *this += other;
            case '-':
                return *this -= other;
            case '*':
                return *this *= other;
            default:
                return *this;
        }
    }
};

inline bool isOperator(char c) {
    if (c == '+' || c == '-' || c == '*')
        return true;
    return false;
}

int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    else if (op == '*')
        return 2;
    return 0;
}

inline bool multi(char c, char last) {
    if (c == 'x')
        if (last == ')' || isdigit(last))
            return true;
    if (c == '(')
        if (isdigit(last) || last == 'x' || last == ')')
            return true;
    return false;
}

int main() {
    string expression;
    cin >> expression;
    int n = expression.length();
    char* operators = new char[n + 1];
    Num* values = new Num[n / 2 + 2];
    int opint = 0;
    int vpoint = 0;
    char last = ' ';
    for (int i = 0; i < n; i++) {
        char c = expression[i];
        if (multi(c, last)) {
            c = '*';
            i--;
        }
        if (c == '(') {
            operators[opint] = c;
            opint++;
        } else if (c == ')') {
            while (opint > 0 && operators[opint - 1] != '(') {
                opint--;
                char op = operators[opint];
                vpoint--;
                values[vpoint - 1].calculate(values[vpoint], op);
            }
            opint--;
        } else if (c == '^') {
            i++;
            int k = expression[i] - '0';
            values[vpoint - 1] ^= k;
            last = '0';
            continue;
        } else if (isOperator(c)) {
            while (opint > 0 &&
                   precedence(c) <= precedence(operators[opint - 1])) {
                opint--;
                char op = operators[opint];
                vpoint--;
                values[vpoint - 1].calculate(values[vpoint], op);
            }
            operators[opint] = c;
            opint++;
        } else {
            int nums[65] = { 0 };
            int h = 0;
            if (c == 'x') {
                last = c;
                h = 1;
                while (i < n - 1 && expression[i + 1] == '^') {
                    i += 2;
                    h *= expression[i] - '0';
                    last = '0';
                }
                nums[h] = 1;
            } else {
                last = '0';
                long long int tmp = c - '0';
                while (i < n - 1 && isdigit(expression[i + 1])) {
                    i++;
                    tmp = 10 * tmp + (long long int)(expression[i] - '0');
                    if (tmp >= M)
                        tmp %= M;
                }
                if (i < n - 1 && expression[i + 1] == 'x') {
                    last = 'x';
                    i++;
                    h = 1;
                    while (i < n - 1 && expression[i + 1] == '^') {
                        i += 2;
                        h *= expression[i] - '0';
                        last = '0';
                    }
                    nums[h] = tmp;
                } else {
                    nums[0] = tmp;
                    h = 0;
                }
            }
            values[vpoint] = Num(nums, h);
            vpoint++;
            continue;
        }
        last = c;
    }
    while (opint > 0) {
        opint--;
        char op = operators[opint];
        vpoint--;
        values[vpoint - 1].calculate(values[vpoint], op);
    }
    bool s = true;
    for (int i = values[0].h; i >= 0; i--) {
        int ans = values[0].nums[i];
        if (s && !ans && i)
            continue;
        s = false;
        if (ans < 0) {
            ans += M;
        }
        if (ans > M)
            ans %= M;
        cout << ans << " ";
    }
    cout << endl;
    delete[] operators;
    delete[] values;
    return 0;
}
