#include <iostream>
#include <time.h>
#include "Define.cpp"

using namespace std;

int main()
{
    srand(time(NULL)); // かき混ぜる

    int array[Define::SIZE];

    for(int i = 0; i < Define::SIZE; i++) // 100個の乱数作成
    {
        array[i] = rand() % (Define::MAX - Define::MIN) + Define::MIN;
        cout << array[i] << "\n";
    }

    for(int j = 0; j < Define::SIZE; j++) // バブルソート
    {
        for(int k = 0; k < Define::SIZE; k++)
        {
            if(array[k] > array[k + Define::current])
                {
                    int box = array[k];
                    array[k] = array[k + Define::current];
                    array[k + Define::current] = box;
                }
        }
    }

    for(int l = 0; l < Define::SIZE; l++) // 表示
    {
        cout << "\n" << array[l];
    }
    return 0;
}