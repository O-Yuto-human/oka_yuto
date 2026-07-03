#include <iostream>
using namespace std;

int main()
{
    float bookValue = 1500;
    float tax = 0.1;
    float bookTax = bookValue * tax;
    float price = bookValue + bookTax;
    cout << bookTax << endl;
    cout << price << endl;

    return 0;
}