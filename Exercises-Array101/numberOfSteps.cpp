#include <iostream>
using namespace std;

int numberOfSteps(int num)
{
    int steps = 0;

    while (num != 0)
    {
        if (num % 2 == 0)
        {
            num /= 2;
            steps++;
        }
        else
        {
            num--;
            steps++;
        }
    }

    return steps;
}

int main()
{
    int num = 8;
    int steps = numberOfSteps(num);
    cout << steps << endl;
    return 0;
}