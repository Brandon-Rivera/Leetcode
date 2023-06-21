#include <iostream>
#include <vector>
#include <string>
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

vector<int> spiralOrder(vector<vector<int>> &matrix)
{

    vector<int> ans;
    int row = matrix.size(), col = matrix[0].size();
    int r = 0, c = 0, length = row * col;
    string option = "right";

    while (ans.size() != length)
    { 
        
        ans.push_back(matrix[r][c]); // 2 0

        //Change direction
        if (c == col-1)
        {
            option = "down";
        }
        if (r == row-1){
            option = "left";
        }
        if (r == row-1 && c == 0){
            option = "up";
        }
        if(r == 1 && c == 0){
            option = "right";
        }

        //Directions
        if( option == "right" ){
            c++;
        }
        else if( option == "left" ){
            c--;
        }
        else if( option == "down" ){
            r++;
        }
        else if( option == "up" ){
            r--;
        }
    }

    return ans;
}

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<vector<int>> matrix2 = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    printVector(spiralOrder(matrix2));
    return 0;
}