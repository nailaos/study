#include <iomanip>
#include <iostream>
using namespace std;

void printBlank(int n) {
    for (int i = 0; i < n; i++)
        cout << " ";
}

void printHeader(int n) {
    for (int i = n + 1; i < n + 4; i++) {
        cout << setw(13) << right << i << "月";
        if (i < n + 3) {
            printBlank(12);
            printBlank(4);
        } else
            cout << endl;
    }
    for (int i = 0; i < 3; i++) {
        cout << "Sun Mon Tue Wed Thu Fri Sat";
        if (i < 2)
            printBlank(4);
        else
            cout << endl;
    }
}

void printCalendar(const int months[], int currentWeek[]) {
    for (int i = 0; i < 12; i += 3) {
        printHeader(i);
        int currentDay[3] = {1, 1, 1};
        while (currentDay[0] <= months[i] || currentDay[1] <= months[i + 1] ||
               currentDay[2] <= months[i + 2]) {
            for (int j = 0; j < 3; j++) {
                if (currentDay[j] <= months[i + j]) {
                    if (currentDay[j] == 1) {
                        printBlank(4 * currentWeek[i + j]);
                        cout << setw(4) << left << currentDay[j];
                        currentDay[j]++;
                        currentWeek[i + j]++;
                        while (currentWeek[i + j]) {
                            currentWeek[i + j] %= 7;
                            if (!currentWeek[i + j])
                                break;
                            cout << setw(4) << left << currentDay[j];
                            currentDay[j]++;
                            currentWeek[i + j]++;
                        }
                    } else {
                        while (currentDay[j] <= months[i + j]) {
                            cout << setw(4) << left << currentDay[j];
                            currentDay[j]++;
                            currentWeek[i + j]++;
                            if (currentWeek[i + j] == 7) {
                                currentWeek[i + j] = 0;
                                break;
                            }
                        }
                        if (currentWeek[i + j])
                            if (j < 2)
                                printBlank(4 * (7 - currentWeek[i + j]));
                    }
                } else {
                    if (j < 2)
                        printBlank(28);
                }
                printBlank(3);
            }
            cout << endl;
        }
        cout << endl;
    }
}

bool isLeapYear(int year) {
    if (year % 4 == 0 && year % 100 != 0)
        return true;
    if (year % 400 == 0)
        return true;
    return false;
}

void init(int year, int months[], int currentWeek[]) {
    int firstDay = 1; // NOTE: 1900年1月1日 Monday
    for (int i = 1900; i < year; i++) {
        firstDay += isLeapYear(i) ? 366 : 365;
        firstDay %= 7;
    }
    if (isLeapYear(year))
        months[1] = 29;
    currentWeek[0] = firstDay;
    for (int i = 1; i < 12; i++) {
        currentWeek[i] = (currentWeek[i - 1] + months[i - 1]) % 7;
    }
}

int main() {
    int year;
    int months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int currentWeek[12] = {0};
    cout << "请输入年份[1900-2100]" << endl;
    cin >> year;
    init(year, months, currentWeek);
    cout << year << "年的日历:\n" << endl;
    printCalendar(months, currentWeek);
    cout << endl;
    return 0;
}
