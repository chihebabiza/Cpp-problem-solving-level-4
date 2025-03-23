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
    cout << "Please enter a day ";
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

stDate AddDaysToDate(stDate &Date, short days)
{
    while (days > 0)
    {
        short remainingDaysInMonth = DaysInMonth(Date.month, Date.year) - Date.day;

        if (days <= remainingDaysInMonth) 
        {
            Date.day += days;
            return Date;
        }

        days -= (remainingDaysInMonth + 1); 
        Date.day = 1;
        Date.month++;

        if (Date.month > 12) 
        {
            Date.month = 1;
            Date.year++;
        }
    }

    return Date;
}

string PrintDate(stDate date)
{
    return to_string(date.day) + "/" + to_string(date.month) + "/" + to_string(date.year);
}

int main()
{
    stDate date = ReadDate();
    short days;
    cout << "\nhow many days to add ";
    cin >> days;
    cout << "Date after adding [" << days << "] is : " << PrintDate(AddDaysToDate(date, days));
    return 0;
}