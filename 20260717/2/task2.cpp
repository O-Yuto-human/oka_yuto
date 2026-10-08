#include <iostream>
#include <queue>

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

// 現在座標保存用
struct Vector2
{
    int x;
    int y;
};

// 既に行ったかどうか
bool visited[SIZE][SIZE] = {}; // 一旦全部false

struct Route
{
    Vector2 point;
    queue<Vector2> path; // ルート出力用 routeはqueue<Vector2>型、中に入るデータはVector2型
};

queue<Route> route;

bool BFS()
{
    while(!route.empty()) // routeが空じゃない間
    {
        Route current = route.front(); // routeの一番上のデータをcurrentに入れる
        route.pop(); // routeの一番上のデータを削除する

        Vector2 currentPoint = current.point; // 現在の座標をcurrentPointに入れる

        // その場所がゴールだった場合
        if (currentPoint.x == 6 && currentPoint.y == 6)
        {
            while (!current.path.empty())
            {
                Vector2 point = current.path.front();
                current.path.pop();

                cout << "(" << point.x << ", " << point.y << ")" << endl;
            }

            return true;
        }
    
        // 既に行ったとしてtrueにする
        visited[currentPoint.y][currentPoint.x] = true;

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
            next.x = currentPoint.x + direction[i].x;
            next.y = currentPoint.y + direction[i].y;

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

            visited[next.y][next.x] = true; // 既に行った場所としてtrueにする(DFSと違い、ここでtrueにする)
            Route nextRoute = current; // currentをnextRouteにコピーする
            nextRoute.point = next; // nextRouteの座標をnextにする
            nextRoute.path.push(next); // nextRouteのpathにnextを入れる
            route.push(nextRoute); // nextRouteをrouteに入れる
        }
    
    }
    return false; // 失敗
}

int main()
{
    Vector2 start = { 2, 3 };

    Route startRoute;
    startRoute.point = start; // startRouteの座標をstartにする
    startRoute.path.push(start); // 初期値をrouteに入れる

    route.push(startRoute); // 初期値をrouteに入れる

    BFS(); // まず初期値をBFS関数にあげる

    return 0;
}