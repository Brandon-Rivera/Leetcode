#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>

using namespace std;

void printVector(vector<int> vector)
{

    cout << "[ ";
    for (int i = 0; i < vector.size(); i++)
    {
        if (vector[i] == vector[vector.size() - 1])
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

int main()
{
    vector<int> a = {1, 2, 3, 4, 6};
    vector<string> b;
    vector<int> sub_vec{a.begin() + 1, a.begin() + a.size()};

    printVector(sub_vec);
    cout << "\nMax Element = " << *max_element(sub_vec.begin(), sub_vec.end());

    return 0;
}

// Array = {20, 0, 1, 2, 10, 0}