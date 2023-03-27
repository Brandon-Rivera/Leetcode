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

int main()
{
    vector<int> a = {1, 2, 3, 4, 6};
    vector<string> b;
    vector<int> sub_vec{a.begin() + 1, a.begin() + a.size()};

    sort(a.begin(),a.end(), greater<int>());

    cout << "Max: " << *max_element(a.begin(), a.end()) << endl;

    printVector(a);

    return 0;
}