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

int main()
{
    vector<int> a = {1, 2, 3, 4, 6};
    vector<string> b;
    vector<int> sub_vec{a.begin() + 1, a.begin() + a.size()};

    printVector(a);
    cout << 1%2 << endl;

    return 0;
}