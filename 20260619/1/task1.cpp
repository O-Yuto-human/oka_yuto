#include <iostream>
#include <time.h>
#include "Define.cpp"

using namespace std;

int main()
{
    srand(time(NULL)); // かき混ぜる

    int array[Define::SIZE];

    for(int i = 0; i < Define::SIZE; i++)
    {
        array[i] = rand() % (Define::MAX - Define::MIN) + Define::MIN;
        cout << array[i] << "\n";

        if(array[i] > array[i + Define::current])
        {
            int box = array[i];
            array[i] = array[i + Define::current];
            array[i + Define::current] = box;
        }
    }
    cout << endl;
    return 0;
}