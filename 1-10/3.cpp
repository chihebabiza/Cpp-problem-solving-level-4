#include <iostream>

using namespace std;

int ReadYear()
{
    int year;
    cout << "Enter a year ";
    cin >> year;
    return year;
}

bool IsLeapYear(int year)
{
    return (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0));
}

int main()
{
    int year = ReadYear();
    if (IsLeapYear(year))
        cout << year << " is leap year\n";
    else
        cout << year << " isn't leep year\n";
    return 0;
}