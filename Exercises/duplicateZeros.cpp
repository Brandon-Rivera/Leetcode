#include <iostream>
#include <vector>
using namespace std;

void duplicateZeros(vector<int> &arr)
{
    for (int i = 0; i < arr.size() - 1; i++)
    {
        if (arr[i] == 0)
        {
            for (int j = arr.size() - 2; j >= i; j--)
            {
                arr[j + 1] = arr[j];
            }
            i++;
        }
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
    vector<int> arr = {1, 0, 2, 3, 0, 4, 5, 0};
    duplicateZeros(arr);
    printVector(arr);

    return 0;
}