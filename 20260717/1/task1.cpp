/*#include <iostream>
using namespace std;

int main
{
    int a[8][8] = 
    {0,0,1,0,0,0,0,0},
    {0,1,1,0,1,0,1,0},
    {0,1,1,0,1,0,1,0},
    {0,0,2,0,1,0,1,0},
    {0,1,0,1,1,1,0,0},
    {0,1,0,1,1,0,0,1},
    {0,0,0,1,1,1,3,1},
    {0,1,0,0,0,1,0,1};

    return 0;
}*/

#include <iostream>
#include <stack>

using namespace std;

// マップサイズ
const int SIZE = 8;

// マップ
int map[SIZE][SIZE] =
{
    {0, 0, 1, 0, 0, 0, 0, 0},
    {0, 1, 1, 0, 1, 0, 1, 0},
    {0, 1, 1, 0, 1, 0, 1, 0},
    {0, 0, 0, 0, 1, 0, 1, 0},
    {0, 1, 0, 1, 1, 1, 0, 0},
    {0, 1, 0, 1, 1, 0, 0, 1},
    {0, 0, 0, 1, 1, 1, 0, 1},
    {0, 1, 0, 0, 0, 1, 0, 1}
};

// 既に行ったかどうか
bool visited[SIZE][SIZE] = {}; // 一旦全部false

// 現在座標保存用
struct Vector2
{
    int x;
    int y;
};

// ルート出力用 routeはstack<Vector2>型、中に入るデータはVector2型
stack<Vector2> route;
// なので、出力用にもう一つ変数を用意する
Vector2 point;

bool DFS(Vector2 current)
{
    
    // その場所がゴールだった場合
    if (current.x == 6 && current.y == 6)
    {
        route.push({ current.x, current.y }); // ゴールの座標をrouteに入れる(再帰処理なので、この座標が一番最初に入る)
        return true; // 成功
    }

    // 既に行ったとしてtrueにする
    visited[current.y][current.x] = true;

    // 上、右、下、左
    Vector2 direction[4] =
    {
        { 0, -1 },
        { 1,  0 },
        { 0,  1 },
        {-1,  0 }
    };

    for (int i = 0; i < 4; i++)
    {
        Vector2 next; // 次に行くところの予定地を保存する変数

        // 上、右、下、左の順で次の予定地を見つける
        next.x = current.x + direction[i].x;
        next.y = current.y + direction[i].y;

        // ↓あり得ない数値だった場合(範囲外・壁・既に行った場所)
        // まず範囲外(0未満や8以上だった場合)
        if (next.x < 0 || next.x >= SIZE ||
            next.y < 0 || next.y >= SIZE)
        {
            continue; // ループを抜けだす
        }

        // マップの行、列を指定して、そこにある数字が1だった場合(壁)
        if (map[next.y][next.x] == 1)
        {
            continue;
        }

        // 既に行った場所だった場合
        if (visited[next.y][next.x])
        {
            continue;
        }

        // 次の場所からDFS
        if (DFS(next)) // 再帰処理 nextからもう一度DFS、それでゴールしてtrue返されたら
                       // if(DFS(next) == true)とも書ける
        {
            route.push({ current.x, current.y }); // その座標を出力用に保存
            return true; // 成功
        }
    }

    return false; // 失敗
}

int main()
{
    Vector2 start = { 2, 3 };

    DFS(start); // まず初期値をDFS関数にあげる

    while(!route.empty()) // routeが空じゃない間
    {
        point = route.top(); // routeの一番上のデータをpointに入れる
        cout << "(" << point.x << ", " << point.y << ")" << endl; // 出力
        route.pop(); // routeの一番上のデータを削除する
    }

    return 0;
}