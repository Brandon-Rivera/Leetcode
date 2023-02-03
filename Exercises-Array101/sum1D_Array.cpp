#include <iostream>
#include <vector>
using namespace std;

vector<int> sum1D_Array( vector<int> nums ){

    vector<int> output;

	for(int i = 0; i < nums.size(); i++){
		if(i == 0){
			output.push_back(nums[i]);
		}
		else if(i == 1){
			output.push_back(nums[i] + nums[i-1]);
		}
		else{
			output.push_back(nums[i] + output[i-1]);
		}
	}

    return output;

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

    vector<int> output, nums = { 1, 2, 3, 4};
    output = sum1D_Array(nums);
    printVector(output);

    return 0;
    
}