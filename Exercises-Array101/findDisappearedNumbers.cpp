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

vector<int> findDisappearedNumbers(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        vector<int> ans;
        
        for(int i = 1; i <= nums.size(); i++)
            if(!binary_search(nums.begin(), nums.end(), i))
                ans.push_back(i);
        
        return ans;
        
    }

int main()
{
    vector<int> nums = {4,3,2,7,8,2,3,1};
    vector<int> ans = findDisappearedNumbers(nums);
    printVector(ans);
    return 0;
}