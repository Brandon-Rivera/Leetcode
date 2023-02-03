//Brandon Rivera Zuñiga
//Time Complexity: O(N)
//Space Complexity: O(1)

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int> numbers, int target)
{
	unordered_map<int, int> hash;
	vector<int> result;

	for (int i = 0; i < numbers.size(); i++) {
		int numberToFind = target - numbers[i];

		if (hash.find(numberToFind) != hash.end()) {
			result.push_back(hash[numberToFind]);
			result.push_back(i);			
			return result;
		}

		hash[numbers[i]] = i;
	}
    
    if(result.empty()){
        cout << "-1" << endl;
    } 

	return result;
}

void printVector(vector<int> vector){
    cout << "[" << vector[0] << "," << vector[1] << "]" << endl;
}

int main(){
    vector<int> numbers = {2,7,11,15};
    vector<int> result;
    int target = 9;

    result = twoSum(numbers, target);
    printVector(result);

    return 0;
}