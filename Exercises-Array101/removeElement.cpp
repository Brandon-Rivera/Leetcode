#include <iostream>
#include <vector>
using namespace std;

int removeElement(vector<int> &nums, int val)
{
    int length = 0;
    vector<int> temp;

    for (int i : nums)
    {
        if (i != val)
        {
            temp.push_back(i);
        }
    }

    nums.clear();
    nums = temp;
    return nums.size();
}

int removeElementInPlace(vector<int> &nums, int val)
{

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == val)
        {
            nums.erase(nums.begin() + i);
            i--;
        }
    }
    return nums.size();
}

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
    vector<int> nums = {3, 2, 2, 3};
    int val = 3;
    cout << removeElementInPlace(nums, val) << endl;
    printVector(nums);

    return 0;
}