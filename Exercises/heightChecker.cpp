#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int heightChecker(vector<int> &heights)
{

    vector<int> h = heights;
    sort(h.begin(), h.end());
    int c = 0;

    for (int i = 0; i < h.size(); i++)
    {
        if (h[i] != heights[i])
        {
            c++;
        }
    }

    return c;
}

int main()
{
    vector<int> heights = {1,1,4,2,1,3};
    cout << heightChecker(heights) << endl;
    return 0;
}