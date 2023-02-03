#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int maximumWealth(vector<vector<int>> accounts)
{

    int sum = 0;
    vector<int> wealht;

    for (int i = 0; i < accounts.size(); i++){
        for (int j = 0; j < accounts[i].size(); j++){
            sum += accounts[i][j];
            wealht.push_back(sum);
        }
        sum = 0;
    }

    return *max_element(wealht.begin(), wealht.end());
}

int main()
{
    vector<vector<int>> accounts = {{1, 2, 3}, {3, 2, 1}};

    cout << maximumWealth(accounts) << endl;

    return 0;
}