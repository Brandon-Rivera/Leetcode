#include <iostream>
#include <vector>
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

vector<int> replaceElements(vector<int> &arr) 
{

    int m = arr[arr.size() - 1];
    arr[arr.size() - 1] = -1;
    if (arr.size() == 1)
        return arr;

    for (int i = arr.size() - 2; i >= 0; i--)
    {
        int temp = arr[i];
        arr[i] = m;
        m = max(temp, m);
    }
    return arr;
}

int main()
{
    vector<int> xd = {17, 18, 5, 4, 6, 1};
    printVector(replaceElements(xd));
    return 0;
}