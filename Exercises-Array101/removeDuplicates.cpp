#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int> &nums)
{

    vector<int> temp;
    temp.push_back(nums[0]);

    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] != nums[i - 1])
        {
            temp.push_back(nums[i]);
        }
    }

    nums.clear();
    nums = temp;
    return nums.size();
}

int removeDuplicatesInPlace(vector<int> &nums)
{

    int index = 1, uniqueElements = 1;

    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] != nums[i - 1])
        {
            nums[index] = nums[i];
            index++;
            uniqueElements++;
        }
        // Solution 1
        // else
        // {
        //     nums.erase(nums.begin() + i);
        //     i--;
        // }
    }

    //Solution 2
    for(int i = 0; i = uniqueElements - nums.size(); i++){
        nums.pop_back();
    }

    return nums.size();
}

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
    // vector<int> nums = {1,1,2};
    vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    cout << "Output: " << removeDuplicatesInPlace(nums) << endl;
    printVector(nums);
    return 0;
}