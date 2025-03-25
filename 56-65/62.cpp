#include <iostream>

using namespace std;

struct stDate
{
    short day;
    short month;
    short year;
};

stDate ReadDate()
{
    stDate date;
    cout << "\nPlease enter a day ";
    cin >> date.day;
    cout << "Please enter a month ";
    cin >> date.month;
    cout << "Please enter a year ";
    cin >> date.year;
    return date;
}

bool IsLeapYear(int year)
{
    return (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0));
}

short DaysInMonth(short month, short year)
{
    short daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && IsLeapYear(year))
        return 29;
    return daysInMonth[month - 1];
}

bool IsValid(stDate date)
{
    return date.year >= 1 &&
           date.day >= 1 && date.day <= DaysInMonth(date.month, date.year) &&
           date.month >= 1 && date.month <= 12;
}

int main()
{
    stDate date = ReadDate();
    if (IsValid(date))
        cout << "\nYES , Date is a valid date";
    else
        cout << "\nNO , Date is NOT a valid date";
    return 0;
}