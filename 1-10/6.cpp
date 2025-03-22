#include <iostream>

using namespace std;

short ReadYear()
{
    short year;
    cout << "Enter a year: ";
    cin >> year;
    return year;
}

short ReadNumberOfMonth()
{
    short number;
    cout << "Enter a month (1-12): ";
    cin >> number;
    return number;
}

bool IsLeapYear(int year)
{
    return (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0));
}

int NumberOfDaysInMonth(short year, short month)
{
    int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    return (month==2)?(IsLeapYear(year)?29:28):daysInMonth[month-1];
}

int main()
{
    short year = ReadYear();
    short month = ReadNumberOfMonth();

    if (month < 1 || month > 12)
    {
        cout << "Invalid month! Please enter a number between 1 and 12.\n";
        return 1;
    }

    cout << "\nNumber of Days in month [" << month << "] is " << NumberOfDaysInMonth(year, month);
    return 0;
}
