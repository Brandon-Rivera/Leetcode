//Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.

// Input: nums = [-4,-1,0,3,10]
// Output: [0,1,9,16,100]

#include <iostream>
#include <vector>
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

vector<int> sortedSquares(vector<int> &nums)
{

    for (int i = 0; i < nums.size(); i++)
    {
        nums[i] = nums[i] * nums[i];
    }

    sort(nums.begin(), nums.end());

    return nums;
}

int main()
{
    vector<int> nums = {-4, -1, 0, 3, 10};
    vector<int> ans = sortedSquares(nums);
    printVector(ans);
    return 0;
}