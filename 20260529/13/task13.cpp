#include <iostream>
using namespace std;

int main()
{
    int colorCode = 0x2DBE60;
    int r = colorCode&0xFF0000;
    r = r >> 16;
    int g = colorCode&0x00FF00;
    g = g >> 8;
    int b = colorCode&0x0000FF;
    cout << r << endl;
    cout << g << endl;
    cout << b << endl;

    return 0;
}