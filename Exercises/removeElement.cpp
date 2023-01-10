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
    vector<int> nums = {3,2,2,3};
    int val = 3;
    cout << removeElement(nums, val) << endl;
    printVector(nums);

    return 0;
}