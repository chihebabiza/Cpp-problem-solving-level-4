#include <iostream>

using namespace std;

struct stDate
{
    short day;
    short month;
    int year;
};

short ReadDay()
{
    short day;
    cout << "Please enter a day ";
    cin >> day;
    return day;
}

short ReadMonth()
{
    short month;
    cout << "Please enter a month ";
    cin >> month;
    return month;
}

int ReadYear()
{
    int year;
    cout << "Please enter a year ";
    cin >> year;
    return year;
}

stDate ReadFullDate()
{
    stDate date;
    date.day = ReadDay();
    date.month = ReadMonth();
    date.year = ReadYear();
    return date;
}

string PrintFullDate(stDate date)
{
    return (to_string(date.day) + "/" + to_string(date.month) + "/" + to_string(date.year));
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

stDate IncreaseDateByXDays(stDate Date, int days)
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

stDate IncreaseDateByOneWeek(stDate Date)
{
    return IncreaseDateByXDays(Date, 7);
}

stDate IncreaseDateByXWeeks(stDate Date, int weeks)
{
    for (int i = 0; i < weeks; i++)
    {
        Date = IncreaseDateByOneWeek(Date);
    }
    return Date;
}

stDate IncreaseDateByOneMonth(stDate Date)
{
    if (Date.month == 12)
    {
        Date.year++;
        Date.month = 1;
    }
    else
        Date.month++;
    short NumberOfDaysInCurrentMonth = DaysInMonth(Date.month, Date.year);
    if (Date.day > NumberOfDaysInCurrentMonth)
        Date.day = NumberOfDaysInCurrentMonth;
    return Date;
}

stDate IncreaseDateByXMonths(stDate Date, int months)
{
    for (int i = 0; i < months; i++)
    {
        Date = IncreaseDateByOneMonth(Date);
    }
    return Date;
}

stDate IncreaseDateByOneYear(stDate Date)
{
    Date.year++;
    if (Date.month == 2 && IsLeapYear(Date.year))
        Date.day = 28;
    return Date;
}

stDate IncreaseDateByXYears(stDate Date, int years)
{
    for (int i = 0; i < years; i++)
    {
        Date = IncreaseDateByOneYear(Date);
    }
    return Date;
}

stDate IncreaseDateByXYearsFastly(stDate Date, int years)
{
    Date.year += years;
    return Date;
}

stDate IncreaseByOneDecade(stDate Date)
{
    Date.year += 10;
}

stDate IncreaseByXDecades(stDate Date, int decades)
{
    return IncreaseDateByXYears(Date, 10 * decades);
}

stDate IncreaseByXDecadesFastly(stDate Date, int decades)
{
    return IncreaseDateByXYearsFastly(Date, 10 * decades);
}

stDate IncreaseDateByOneMilennium(stDate Date)
{
    return IncreaseDateByXYearsFastly(Date, 1000);
}

int main()
{
    stDate date = ReadFullDate();
    stDate IncreasedByOneDay = IncreaseDateByXDays(date, 1);
    stDate IncreasedBy10Days = IncreaseDateByXDays(IncreasedByOneDay, 10);
    stDate IncreasedByOneWeek = IncreaseDateByOneWeek(IncreasedBy10Days);
    stDate IncreasedBy10Weeks = IncreaseDateByXWeeks(IncreasedByOneWeek, 10);
    stDate IncreasedByOneMonth = IncreaseDateByOneMonth(IncreasedBy10Weeks);
    stDate IncreasedBy5Months = IncreaseDateByXMonths(IncreasedByOneMonth, 5);
    stDate IncreasedByOneYear = IncreaseDateByOneYear(IncreasedBy5Months);
    stDate IncreasedBy10Years = IncreaseDateByXYears(IncreasedByOneYear, 10);
    stDate IncreasedBy10YearsFastly = IncreaseDateByXYearsFastly(IncreasedByOneYear, 10);
    stDate IncreasedByOneDecade = IncreaseByOneDecade(IncreasedBy10YearsFastly);
    stDate IncreadedBy10Decades = IncreaseByXDecades(IncreasedByOneDecade, 10);
    stDate IncreadedBy10DecadesFastly = IncreaseByXDecadesFastly(IncreasedByOneDecade, 10);
    stDate IncreadedByOneMillennuim = IncreaseDateByOneMilennium(IncreadedBy10DecadesFastly);

    cout << "\nDate after : ";
    cout << "\n01- Adding one day is :" << PrintFullDate(IncreasedByOneDay);
    cout << "\n02- Adding 10 days is :" << PrintFullDate(IncreasedBy10Days);
    cout << "\n03- Adding one week is :" << PrintFullDate(IncreasedByOneWeek);
    cout << "\n04- Adding 10 weeks is :" << PrintFullDate(IncreasedBy10Weeks);
    cout << "\n05- Adding one month is :" << PrintFullDate(IncreasedByOneMonth);
    cout << "\n06- Adding 5 months is :" << PrintFullDate(IncreasedBy5Months);
    cout << "\n07- Adding one year is :" << PrintFullDate(IncreasedByOneYear);
    cout << "\n08- Adding 10 years is :" << PrintFullDate(IncreasedBy10Years);
    cout << "\n09- Adding 10 years (Faster) is :" << PrintFullDate(IncreasedBy10YearsFastly);
    cout << "\n10- Adding one decade is :" << PrintFullDate(IncreasedByOneDecade);
    cout << "\n11- Adding 10 decades is :" << PrintFullDate(IncreadedBy10Decades);
    cout << "\n12- Adding 10 decades (Faster) is :" << PrintFullDate(IncreadedBy10DecadesFastly);
    cout << "\n13- Adding one century is :" << PrintFullDate(IncreadedBy10DecadesFastly);
    cout << "\n14- Adding one millennium is :" << PrintFullDate(IncreadedBy10Decades);

    return 0;
}