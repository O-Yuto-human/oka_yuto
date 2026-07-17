#include <iostream>
#include <time.h>
#include "Define.cpp"

using namespace std;

void Recursion(int array[],int start,int end)
{
    if(start >= end) // 交差したら終わり
    {
        return;
    }

    int pivot = array[start];
    int left = start + 1; // 一個目はpivotだから見なくていい
    int right = end;

    while(left <= right)
    {
        while(left <= end && pivot > array[left]) // 飛び越えないように
        {
            left++;
        }
        while(right >= start && pivot < array[right])
        {
            right--;
        }
        
        if(left <= right) // 交換すべき値が見つかったら
        {
            int box = array[left];
            array[left] = array[right];
            array[right] = box; // 位置交換

            left++;
            right--; // 同じところをもう一度交換しないように
        } // 最終的にrightはpivot以下の値がある場所(pivotを置く最適な位置)にある
    }

    // pivotの位置確定
    int box = array[start];
    array[start] = array[right];
    array[right] = box;

    Recursion(array,start,right - 1); 
    Recursion(array,right + 1,end); // 分割した二つともにもう一度使う
    // pivot入れた後に、比較しないため
}

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

    Recursion(array,0,Define::SIZE - 1); // 再帰

    for(int i = 0; i < Define::SIZE; i++) // ソート済みの配列出力
    {
        cout << array[i] << endl;
    }

    // pivot 最初の閾値は、乱数なので今回は配列の0番目ー
    // left (array[1]) 左から、閾値より大きい値(最終そこにいてはいけない値)を探していく
    // right (array[99]) 右から、閾値より小さい値(最終そこにいてはいけない値)を探していく

}