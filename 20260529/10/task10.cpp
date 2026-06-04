#include<iostream>
using namespace std;

int main()
{
    for(int answer = 1; answer <= 100; answer++)
    {
        if((answer + 50) % 2 == 0 && answer >= 50)
        {
            cout << answer << endl;
        }
    }
}