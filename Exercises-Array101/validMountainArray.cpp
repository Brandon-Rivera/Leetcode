#include <iostream>
#include <vector>
using namespace std;

bool validMountainArray(vector<int> &arr)
{
    int length = arr.size() - 1;
    int i = 0;
    while (i < length && arr[i] < arr[i + 1])
    {
        i++;
    }
    if (i == length || i == 0)
    {
        return false;
    }
    while (i < length && arr[i] > arr[i + 1])
    {
        i++;
    }
    if (i == length)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    vector<int> arr = {0, 1, 2, 3, 4, 8, 9, 10, 11, 12, 11};
    cout << validMountainArray(arr) << endl;
    return 0;
}