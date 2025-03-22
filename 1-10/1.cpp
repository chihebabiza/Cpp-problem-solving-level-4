#include <iostream>
#include <string>

using namespace std;

string NumberToText(int number)
{
    string numbers[] = {
        "", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
        "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen",
        "sixteen", "seventeen", "eighteen", "nineteen"};

    if (number == 0)
        return "zero";
    if (number > 0 && number < 20)
        return (numbers[number]);

    string tens[] = {
        "", "", "twenty", "thirty", "forty", "fifty",
        "sixty", "seventy", "eighty", "ninety"};

    if (number >= 20 && number < 100)
        return (tens[number / 10] + " " + numbers[number % 10]);

    if (number >= 100 && number < 1000)
        return NumberToText(number / 100) + " hundred " + NumberToText(number % 100);

    if (number >= 1000 && number < 1000000)
        return NumberToText(number / 1000) + " thousand " + NumberToText(number % 1000);

    if (number >= 1000000 && number < 1000000000)
        return NumberToText(number / 1000000) + " million " + NumberToText(number % 1000000);

    if (number >= 1000000000)
        return NumberToText(number / 1000000000) + " billion " + NumberToText(number % 1000000000);
}

int main()
{
    int number;
    cout << "Enter a number: ";
    cin >> number;

    cout << "Number in words: " << NumberToText(number) << endl;

    return 0;
}
