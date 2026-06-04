#include<iostream>
using namespace std;

int main()
{
    for(int answer = 1; answer <= 100; answer++)
    {
        if(answer % 3 == 0 && answer % 5 == 0)
        {
            cout << answer << endl;
        }
    }
}