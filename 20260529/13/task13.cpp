#include<iostream>
using namespace std;

int main()
{
    int _color_code = 0x2DBE60;
    int _r = _color_code&0xFF0000;
    _r = _r >> 16;
    int _g = _color_code&0x00FF00;
    _g = _g >> 8;
    int _b = _color_code&0x0000FF;
    cout << _r << endl;
    cout << _g << endl;
    cout << _b << endl;
}