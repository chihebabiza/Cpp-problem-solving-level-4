#include <iostream>

using namespace std;

short ReadYear()
{
    short year;
    cout << "Enter a year ";
    cin >> year;
    return year;
}

bool IsLeapYear(int year)
{
    return (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0));
}

int NumberOfDaysInYear(short year)
{
    return IsLeapYear(year) ? 366 : 365;
}

int NumberOfHoursInYear(short year)
{
    return NumberOfDaysInYear(year) * 24;
}

int NumberOfMinutesInYear(short year)
{
    return NumberOfHoursInYear(year) * 60;
}

int NumberOfSecondsInYear(short year)
{
    return NumberOfMinutesInYear(year) * 60;
}

int main()
{
    short year = ReadYear();
    cout << "\nNumber of Days in year [" << year << "] is " << NumberOfDaysInYear(year);
    cout << "\nNumber of Hours in year [" << year << "] is " << NumberOfHoursInYear(year);
    cout << "\nNumber of Minutes in year [" << year << "] is " << NumberOfMinutesInYear(year);
    cout << "\nNumber of Seconds in year [" << year << "] is " << NumberOfSecondsInYear(year);
    return 0;
}