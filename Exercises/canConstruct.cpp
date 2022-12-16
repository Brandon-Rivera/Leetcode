// HashMap
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

bool canConstruct(string ransomNote, string magazine)
{
    unordered_map<char, int> myMap;
    for (int i = 0; i < magazine.size(); ++i)
        myMap[magazine[i]]++;
    for (int i = 0; i < ransomNote.size(); ++i)
        myMap[ransomNote[i]]--;
    for (auto it = myMap.begin(); it != myMap.end(); ++it)
        if (it->second < 0)
            return false;
    return true;
}

int main()
{
    string ransomNote = "aa";
    string magazine = "ab";
    cout << canConstruct(ransomNote, magazine);

    return 0;
}