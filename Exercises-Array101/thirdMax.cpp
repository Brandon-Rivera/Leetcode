// Given an integer array nums, return the third distinct maximum number in this array. If the third maximum does not exist, return the maximum number.

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

int thirdMax(vector<int> &nums)
{

    sort(nums.begin(), nums.end(), greater<int>());
    int max = nums[0], cnt = 0;

    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] != max && cnt < 2)
        {
            max = nums[i];
            cnt++;
        }
    }

    if (cnt < 2)
    {
        max = *max_element(nums.begin(), nums.end());
    }

    return max;
}

int main()
{
    vector<int> nums = {-3,-2,-1,0};
    //vector<int> nums = {5, 5, 3, 2, 2, 1 };
    cout << thirdMax(nums) << endl;
    return 0;
}