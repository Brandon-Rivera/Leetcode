#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    if (m == 0)
    {
        for (int i = 0; i < n; i++)
        {
            nums1[i] = nums2[i];
        }
    }

    if (m != 0 && n != 0)
    {
        for (int i = m; i < n + m; i++)
        { // i=6
            nums1[i] = nums2[i - m];
        }
        sort(nums1.begin(), nums1.end());
    }
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
    vector<int> nums1 = {1,2,3,0,0,0}, nums2 = {2, 5, 6};
    int m = 3, n = 3;
    merge(nums1, m, nums2, n);
    printVector(nums1);

    return 0;
}