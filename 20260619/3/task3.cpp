#include <iostream>
#include <time.h>
#include "Define.cpp"

using namespace std;

int main()
{
    srand(time(NULL)); // かき混ぜる

    int array[Define::SIZE];
    int count = 0; // ソートできた数値の数

    for(int i = 0; i < Define::SIZE; i++) // 100個の乱数作成
    {
        array[i] = rand() % (Define::MAX - Define::MIN) + Define::MIN;
        cout << array[i] << "\n";
    }

    cout << "\n";

    for(int i = 0; i < Define::SIZE; i++)
    {
        int box = array[i]; // まず保存
        for(int j = count - 1; j >= 0; j--) // ソートしたい数値の前の数値と比べ、一番処理が長いとindex0まで中身を見るからj >= 0
        {
            if(array[j] < box) // ソート
            {
                // array[i]がソートしたい数値
                // array[j]がすでにソートされてる、array[i]の一個前の数値の要素番号
            }
            else
            {
                while(j >= 0 && box < array[j]) // 配列をずらさないと挿入できない
                {
                    array[j + 1]= array[j]; // ソートしたい数値の要素番号のところに、その一つ前の要素番号の中の要素をコピーする
                    // 例 1000,3000,5000,2000→　int box = 2000　→1000,3000,5000,5000にする
                    j--;
                }
               
                array[j + 1] = box; // 最後の比較で、入れたい場所よりjが一つ下がってるから、+1する
            }
        }

        count++;
    }

    for(int i = 0; i < Define::SIZE; i++)
    {
        cout << array[i] << endl; // もし上のループ内で出力すると、完成前のソートが出てくる
    }

    return 0;
}