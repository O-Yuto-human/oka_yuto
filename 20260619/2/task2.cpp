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

    cout << "\n";

    for(int i = 0; i < Define::SIZE; i++)
    {
        // 2,0,4,3,5
        int minValue = array[i];
        // 最小値容疑のものをminValueに入れる
        int minValueIndex = i;
        // その証拠(index)ごと保存する

        for(int j = i; j < Define::SIZE; j++)
        {
           // 配列全体から最小の数値を探す
           if(minValue > array[j])
           {
                // 容疑者入れ替え
                minValue = array[j];
                minValueIndex = j;
           }
        }

        if(minValueIndex != i)
        {
            // 容疑者が変わっていたら
            int box = array[i];
            array[i] = minValue;
            array[minValueIndex] = box;
        }

        cout << array[i] << endl;
    }

    return 0;
}