#include <iostream>
using namespace std;

int main()
{
    for(int answer = 1; answer <= 100; answer++)
    {
        if(answer % 10 == 0 || answer % 15 == 0)
        {
            cout << answer << endl;
        }
    }
    return 0;
}