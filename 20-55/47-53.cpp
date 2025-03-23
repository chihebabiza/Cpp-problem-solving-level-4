#include <iostream>
#include <ctime>

using namespace std;

struct stDate
{
    short weekDay;
    short day;
    short month;
    int year;
};

string GetWeekDayName(short number)
{
    switch (number)
    {
    case 0:
        return ("Sunday");
    case 1:
        return ("Monday");
    case 2:
        return ("Tuesday");
    case 3:
        return ("Wednesday");
    case 4:
        return ("Thursday");
    case 5:
        return ("Friday");
    case 6:
        return ("Saturday");
    default:
        return ("Invalid day number");
    }
}

stDate GetSystemDate()
{
    stDate date;
    time_t t = time(0);
    tm *now = localtime(&t);

    date.weekDay = now->tm_wday;
    date.day = now->tm_mday;
    date.month = now->tm_mon + 1;
    date.year = now->tm_year + 1900;
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

short DaysFromBeginingYear(stDate Date)
{
    short numDays = 0;
    for (short i = 1; i < Date.month; i++)
    {
        numDays += DaysInMonth(i, Date.year);
    }
    return numDays + Date.day;
}

void PrintTodayDate(stDate Date)
{
    cout << "\nToday is " << GetWeekDayName(Date.weekDay) << " , " << Date.day << "/" << Date.month << "/" << Date.year;
}

bool IsWeekEnd(short dayWeek)
{
    return (dayWeek == 5 || dayWeek == 6);
}

bool IsBusinessDay(short dayWeek)
{
    return (!IsWeekEnd(dayWeek));
}

short DaysUntilTheEndOfWeek(short weekDay)
{
    return 7 - weekDay + 1;
}

short DaysUntilTheEndOfMonth(stDate Date)
{
    return DaysInMonth(Date.month, Date.year) - Date.day;
}

short DaysUntilTheEndOfYear(stDate Date)
{
    return 365 - DaysFromBeginingYear(Date);
}

int main()
{
    stDate today = GetSystemDate();
    PrintTodayDate(today);

    cout << "\n\nIs it end of week ?";
    if (IsWeekEnd(today.weekDay))
        cout << "\nYes it is a week end";
    else
        cout << "\nNo it is NOT a week end";

    cout << "\n\nIs it a business day?";
    if (IsBusinessDay(today.weekDay))
        cout
            << "\nYes it is a business day";
    else
        cout << "\nNo it is NOT a business day";

    cout << "\n\nDays until end of week : " << DaysUntilTheEndOfWeek(today.weekDay) << " Day(s)";
    cout << "\n\nDays until end of month : " << DaysUntilTheEndOfMonth(today) << " Day(s)";
    cout << "\n\nDays until end of year : " << DaysUntilTheEndOfYear(today) << " Day(s)";
    
    return 0;
}