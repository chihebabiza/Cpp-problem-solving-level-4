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

stDate DecreaseDateByXDays(stDate Date, int days)
{
    while (days > 0)
    {

        if (days < Date.day)
        {
            Date.day -= days;
            return Date;
        }

        days -= Date.day;
        Date.day = DaysInMonth(Date.month, Date.year);
        Date.month--;

        if (Date.month < 1)
        {
            Date.month = 12;
            Date.year--;
        }
    }

    return Date;
}

stDate DecreaseDateByOneWeek(stDate Date)
{
    return DecreaseDateByXDays(Date, 7);
}

stDate DecreaseDateByXWeeks(stDate Date, int weeks)
{
    for (int i = 0; i < weeks; i++)
    {
        Date = DecreaseDateByOneWeek(Date);
    }
    return Date;
}

stDate DecreaseDateByOneMonth(stDate Date)
{
    if (Date.month == 1)
    {
        Date.year--;
        Date.month = 12;
    }
    else
        Date.month--;
    short NumberOfDaysInCurrentMonth = DaysInMonth(Date.month, Date.year);
    if (Date.day > NumberOfDaysInCurrentMonth)
        Date.day = NumberOfDaysInCurrentMonth;
    return Date;
}

stDate DecreaseDateByXMonths(stDate Date, int months)
{
    for (int i = 0; i < months; i++)
    {
        Date = DecreaseDateByOneMonth(Date);
    }
    return Date;
}

stDate DecreaseDateByOneYear(stDate Date)
{
    Date.year--;
    if (Date.month == 2 && IsLeapYear(Date.year))
        Date.day = 28;
    return Date;
}

stDate DecreaseDateByXYears(stDate Date, int years)
{
    for (int i = 0; i < years; i++)
    {
        Date = DecreaseDateByOneYear(Date);
    }
    return Date;
}

stDate DecreaseDateByXYearsFastly(stDate Date, int years)
{
    Date.year -= years;
    if (Date.month == 2 && IsLeapYear(Date.year))
        Date.day = 28;
    return Date;
}

stDate DecreaseByOneDecade(stDate Date)
{
    Date.year -= 10;
    return Date;
}

stDate DecreaseByXDecades(stDate Date, int decades)
{
    return DecreaseDateByXYears(Date, 10 * decades);
}

stDate DecreaseByXDecadesFastly(stDate Date, int decades)
{
    return DecreaseDateByXYearsFastly(Date, 10 * decades);
}

stDate DecreaseByOneCentury(stDate Date)
{
    Date.year -= 100;
    return Date;
}

stDate DecreaseDateByOneMilennium(stDate Date)
{
    return DecreaseDateByXYearsFastly(Date, 1000);
}

int main()
{
    stDate date = ReadFullDate();

    date = DecreaseDateByXDays(date, 1);
    cout << "\n01- Subtracting one day is :" << PrintFullDate(date);

    date = DecreaseDateByXDays(date, 10);
    cout << "\n02- Subtracting 10 days is :" << PrintFullDate(date);

    date = DecreaseDateByOneWeek(date);
    cout << "\n03- Subtracting one week is :" << PrintFullDate(date);

    date = DecreaseDateByXWeeks(date, 10);
    cout << "\n04- Subtracting 10 weeks is :" << PrintFullDate(date);

    date = DecreaseDateByOneMonth(date);
    cout << "\n05- Subtracting one month is :" << PrintFullDate(date);

    date = DecreaseDateByXMonths(date, 5);
    cout << "\n06- Subtracting 5 months is :" << PrintFullDate(date);

    date = DecreaseDateByOneYear(date);
    cout << "\n07- Subtracting one year is :" << PrintFullDate(date);

    date = DecreaseDateByXYears(date, 10);
    cout << "\n08- Subtracting 10 years is :" << PrintFullDate(date);

    date = DecreaseDateByXYearsFastly(date, 10);
    cout << "\n09- Subtracting 10 years (Faster) is :" << PrintFullDate(date);

    date = DecreaseByOneDecade(date);
    cout << "\n10- Subtracting one decade is :" << PrintFullDate(date);

    date = DecreaseByXDecades(date, 10);
    cout << "\n11- Subtracting 10 decades is :" << PrintFullDate(date);

    date = DecreaseByXDecadesFastly(date, 10);
    cout << "\n12- Subtracting 10 decades (Faster) is :" << PrintFullDate(date);

    date = DecreaseByOneCentury(date);
    cout << "\n13- Subtracting one century is :" << PrintFullDate(date);

    date = DecreaseDateByOneMilennium(date);
    cout << "\n14- Subtracting one millennium is :" << PrintFullDate(date);

    return 0;
}