#include<iostream>
#include<vector>
#include<string>
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

vector<int> findDiagonalOrder(vector<vector<int>>& mat) {

    bool up = true;
    int r = 0, c = 0;
    int row = mat.size(), col = mat[0].size();
    vector<int> ans;

    while(r < row && c < col){

        if(up){
            ans.push_back(mat[r][c]);
            c++;
            r--;

            if( c == col ){
                r+=2;
                c--;
                up = false;
            }
            else if(r < 0){
                r++;
                up = false;
            }
        }
        else{
            ans.push_back(mat[r][c]);
            c--;
            r++;
            
            if( r == row ){
                c+=2;
                r--;
                up = true;
            }
            else if(c < 0){
                c++;
                up = true;
            }
        }
    }

    return ans;

}

int main()
{
    //vector<vector<int>> mat = {{1,2,3},{4,5,6},{7,8,9}};
    vector<vector<int>> mat = {{1,2},{3,4}};
    printVector(findDiagonalOrder(mat));
    return 0;
}