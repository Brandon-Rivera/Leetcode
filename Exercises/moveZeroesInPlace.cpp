#include <iostream>
#include <vector>
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

void moveZeroes(vector<int> &nums)
{

    int lastNonZeroFoundAt = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != 0)
        {
            cout << "Begin: " << lastNonZeroFoundAt;
            nums[lastNonZeroFoundAt++] = nums[i];
            cout << " Last: " << lastNonZeroFoundAt << endl;
        }
    }

    for (int i = lastNonZeroFoundAt; i < nums.size(); i++)
    {
        nums[i] = 0;
    }
}

int main()
{
    vector<int> nums = {0, 1, 0, 3, 12};
    moveZeroes(nums);
    printVector(nums);
    return 0;
}