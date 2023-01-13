// Input: arr = [10,2,5,3]
// Output: true
// Explanation: For i = 0 and j = 2, arr[i] == 10 == 2 * 5 == 2 * arr[j]

// Input: arr = [3,1,7,11]
// Output: false
// Explanation: There is no i and j that satisfy the conditions. And i != j

#include <iostream>
#include <vector>
using namespace std;

bool checkIfExist(vector<int> &arr)
{

    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr.size(); j++)
        {
            if (arr[i] == (2 * arr[j]) && i != j)
            {
                return true;
            }
        }
    }

    return false;
}

int main()
{
    vector<int> arr = {-2, 0, 10, -19, 4, 6, -8};
    cout << checkIfExist(arr) << endl;
    cout << 6%2 << endl;
    return 0;
}