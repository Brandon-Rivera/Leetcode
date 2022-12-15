#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> fizzBuzz(int n)
{
    vector<string> output;

    for (int i = 1; i <= n; i++)
    {
        if ((i % 3 == 0) && (i % 5 == 0))
        {
            output.push_back("FizzBuzz");
        }
        else if ((i % 3 == 0) && (i % 5 != 0))
        {
            output.push_back("Fizz");
        }
        else if ((i % 3 != 0) && (i % 5 == 0))
        {
            output.push_back("Buzz");
        }
        else
        {
            output.push_back(to_string(i));
        }
    }

    return output;
}

void printVector( vector<string> vector){

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
    int n = 15;
    vector<string> output;

    output = fizzBuzz(n);

    printVector(output);

    return 0;
}
