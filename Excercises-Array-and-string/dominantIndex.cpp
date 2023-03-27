// Determine whether the largest element in the array is at least twice as much as every other number in the array. 
// If it is, return the index of the largest element, or return -1 otherwise.
// Input: nums = [3,6,1,0]
// Output: 1
// Explanation: 6 is the largest integer.
// For every other number in the array x, 6 is at least twice as big as x.
// The index of value 6 is 1, so we return 1.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dominantIndex(vector<int> &nums)
{

    int max = *max_element(nums.begin(), nums.end()), idx = 0;

    for (int i : nums)
        if ((i * 2 > max) && (i * 2 != max * 2))
            return -1;

    for (int i = 0; i < nums.size(); i++)
        if (nums[i] == max)
            idx = i;

    return idx;
}

int main()
{
    vector<int> nums = {3, 6, 1, 0};
    cout << "Dominant Index: " << dominantIndex(nums) << endl;
    return 0;
}