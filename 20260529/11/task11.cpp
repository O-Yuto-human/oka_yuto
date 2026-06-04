#include<iostream>
using namespace std;

int main()
{
    float _bookvalue = 1500;
    float _tax = 0.1;
    float _booktax = _bookvalue * _tax;
    float _price = _bookvalue + _booktax;
    cout << _booktax << endl;
    cout << _price << endl;
}