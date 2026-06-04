#include<iostream>
using namespace std;

int main()
{
    float _special_price = 150;
    float _normal_price = 200;
    float _tax = 0.1;
    float _special_value = _special_price + _special_price * _tax;
    float _normal_value = _normal_price + _normal_price * _tax;
    cout << _special_value << endl;
    cout << _normal_value << endl;
}