#include <iostream>
using namespace std;

int main()
{
    float specialPrice = 150;
    float normalPrice = 200;
    float tax = 0.1;
    float specialValueTax = specialPrice * tax;
    float normalValueTax = normalPrice * tax;
    float specialValue = specialPrice + specialValueTax;
    float normalValue = normalPrice + normalValueTax;
  
    cout << specialValue << endl;
    cout << specialValueTax << endl;
    cout << normalValue << endl;
    cout << normalValueTax << endl;

    return 0;
}