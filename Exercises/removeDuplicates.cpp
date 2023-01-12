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

void printVector( vector<int> vector){

    cout << "[ ";
    for(int i = 0; i < vector.size(); i++){
        if(vector[i] == vector[vector.size()-1]){
            cout << vector[i] << " ";
        } else {
            cout << vector[i] << ", ";
        }
    }
    cout << "] ";

}

int main()
{
    //vector<int> nums = {1,1,2};
    vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    cout << "Output: " << removeDuplicates(nums) << endl;
    printVector(nums);
    return 0;
}