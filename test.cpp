#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int main(){
    vector<int> a = {1, 2, 3, 4, 6};

    cout << *max_element(a.begin(), a.end()) << endl;

    return 0;
}