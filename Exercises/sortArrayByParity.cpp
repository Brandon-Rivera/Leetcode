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

vector<int> sortArrayByParity(vector<int> &nums)
{

    if (nums.empty())
    {
        return nums;
    }

    int checkedElements = 0;

    for (int i = 0; i < nums.size(); i++)
    {

        if (checkedElements == nums.size())
        {
            break;
        }

        if ( nums[i] % 2 != 0 && nums[i] != 0)
        {
            nums.push_back(nums[i]);
            nums.erase(nums.begin() + i);
            i--;
        }

        checkedElements++;
    }

    return nums;
}

int main()
{
    vector<int> nums = {1,0}; // {3,5,0,1}
    printVector(sortArrayByParity(nums));
    return 0;
}