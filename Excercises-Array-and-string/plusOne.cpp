#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void printVector(vector<int> vector)
{

    cout << "[ ";
    for (int i = 0; i < vector.size(); i++)
    {
        if (i == vector.size() - 1)
        {
            cout << vector[i] << " ";
        }
        else
        {
            cout << vector[i] << ", ";
        }
    }
    cout << "] ";
}

vector<int> plusOne(vector<int> &digits)
{
    int n = digits.size() - 1;

    for (int i = n; i >= 0; --i)
    {
        if (digits[i] == 9)
            digits[i] = 0;
        else
        {
            digits[i] += 1;
            return digits;
        }
    }
    digits.push_back(0);
    digits[0] = 1;
    return digits;
}

int main()
{
    vector<int> digits = {1, 2, 3};

    printVector(plusOne(digits));

    return 0;
}