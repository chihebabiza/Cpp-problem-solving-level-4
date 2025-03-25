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

bool IsBeforeDate(stDate date1, stDate date2)
{
    return (date1.year < date2.year) ||
           (date1.year == date2.year && date1.month < date2.month) ||
           (date1.year == date2.year && date1.month == date2.month && date1.day < date2.day);
}

bool IsEqual(stDate date1, stDate date2)
{
    return (date1.year == date2.year && date1.month == date2.month && date1.day == date2.day);
}

bool IsAfterDate(stDate date1, stDate date2)
{
    return !IsBeforeDate(date1, date2);
}

short CompareDates(stDate date1, stDate date2)
{
    return IsEqual(date1, date2) ? 0 : (IsAfterDate(date1, date2) ? 1 : -1);
}

int main()
{
    struct stDate Period[2];

    stDate date1 = ReadDate();
    stDate date2 = ReadDate();

    cout << "\nCompare result : " << CompareDates(date1, date2);

    return 0;
}