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

short ReadDay()
{
    short day;
    cout << "Please enter a day: ";
    cin >> day;
    return day;
}

bool IsLeapYear(int year)
{
    return (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0));
}

short DayOfWeekOrder(short Day, short Month, short Year)
{
    short a, y, m;
    a = (14 - Month) / 12;
    y = Year - a;
    m = Month + (12 * a) - 2;

    // Returns 0=Sunday, 1=Monday, ..., 6=Saturday
    return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

string DayName(short number)
{
    switch (number)
    {
    case 0:
        return "Sunday";
    case 1:
        return "Monday";
    case 2:
        return "Tuesday";
    case 3:
        return "Wednesday";
    case 4:
        return "Thursday";
    case 5:
        return "Friday";
    case 6:
        return "Saturday";
    default:
        return "Invalid day";
    }
}

int main()
{
    short year = ReadYear();
    short month = ReadMonth();
    short day = ReadDay();

    short order = DayOfWeekOrder(day, month, year);

    cout << "\nDate: " << day << " / " << month << " / " << year;
    cout << "\nDay order: " << order;
    cout << "\nDay name: " << DayName(order);

    return 0;
}
