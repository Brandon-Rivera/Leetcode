#include <iostream>
#include <vector>
using namespace std;

string intToRoman2(int num) //60
{
    string roman = "IVXLCDM";
    string str;
    int i = 0;
    while (num)
    {
        int r = num % 10;
        if (r < 4)
        {
            for (int j = 0; j < r; j++)
            {
                str += roman[i * 2];
            }
        }
        else if (r == 4)
        {
            str += roman[i * 2 + 1];
            str += roman[i * 2];
        }
        else if (r < 9)
        {
            for (int j = 0; j < r - 5; j++) //1
            {
                str += roman[i * 2];
            }
            str += roman[i * 2 + 1];
        }
        else
        {
            str += roman[i * 2 + 2];
            str += roman[i * 2];
        }
        num /= 10;
        i++;
    }
    reverse(str.begin(), str.end());
    return str;
}

string intToRoman(int num)
{
    int normal[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    string roman[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    string res;
    for (int i = 0; i < 13; i++)
    {
        while (num >= normal[i])
        {
            res.append(roman[i]);
            num -= normal[i];
        }
    }
    return res;
}

int main()
{
    int num = 60;
    cout << "Num: " << intToRoman(num) << endl;
    return 0;
}