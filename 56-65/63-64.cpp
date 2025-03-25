#include <iostream>
#include <vector>

using namespace std;

struct stDate
{
    short day;
    short month;
    short year;
};

vector<string> SplitString(string S1, string Delim)
{
    vector<string> vString;
    short pos = 0;
    string sWord;
    while ((pos = S1.find(Delim)) != std::string::npos)
    {
        sWord = S1.substr(0, pos);
        if (sWord != "")
        {
            vString.push_back(sWord);
        }
        S1.erase(0, pos + Delim.length());
    }
    if (S1 != "")
    {
        vString.push_back(S1);
    }
    return vString;
}

stDate StringToDate(string &StringDate)
{
    stDate Date;
    vector<string> vDate = SplitString(StringDate, "/");
    Date.day = stoi(vDate[0]);
    Date.month = stoi(vDate[1]);
    Date.year = stoi(vDate[2]);
    return Date;
}

string DateToString(stDate &date)
{
    return to_string(date.day) + "/" + to_string(date.month) + "/" + to_string(date.year);
}

int main()
{
    string date;
    stDate Date;
    cout << "\nPlease enter a date dd/mm/yyyy ";
    cin >> date;

    Date = StringToDate(date);

    cout << "\nDay : " << Date.day;
    cout << "\nMonth : " << Date.month;
    cout << "\nYear : " << Date.year;

    date = DateToString(Date);

    cout << "\nYou Entered " << date;

    return 0;
}