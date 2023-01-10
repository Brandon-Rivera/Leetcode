#include <iostream>
#include <vector>
using namespace std;

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
    vector<int> a = {1, 2, 3, 4, 5};
    printVector(a);
    return 0;
}