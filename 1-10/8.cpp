#include <iostream>

using namespace std;

short ReadYear()
{
    short year;
    cout << "Please enter a year: ";
    cin >> year;
    return year;
}

short ReadMonth()
{
    short month;
    cout << "Please enter a month (1-12): ";
    cin >> month;
    return month;
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

short DayOfWeekOrder(short Month, short Year)
{
    short a, y, m;
    a = (14 - Month) / 12;
    y = Year - a;
    m = Month + (12 * a) - 2;
    return (1 + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

void PrintCalendar(short Month, short Year)
{
    const string dayNames[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
    const string monthNames[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

    cout << "\n_______________" << monthNames[Month - 1] << "_______________\n";

    for (short i = 0; i < 7; i++)
    {
        cout << dayNames[i] << "  ";
    }
    cout << "\n";

    short firstDay = DayOfWeekOrder(Month, Year);
    short totalDays = DaysInMonth(Month, Year);
    short day = 1;

    for (short i = 0; i < firstDay; i++)
    {
        cout << "     ";
    }

    for (short i = firstDay; day <= totalDays; i++)
    {
        cout << (day < 10 ? "  " : " ") << day << "  ";
        if ((i + 1) % 7 == 0)
            cout << "\n";
        day++;
    }
    cout << "\n_________________________________\n";
}

int main()
{
    short year = ReadYear();
    short month = ReadMonth();
    PrintCalendar(month, year);
    return 0;
}
