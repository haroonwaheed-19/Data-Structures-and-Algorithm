#include <iostream>
using namespace std;

// power function using recursive call
int power(int base, int exp)
{
    // base case
    if (exp == 0)
    {
        return 1;
    }
    // recursive call
    return base * power(base, exp - 1);
}
int main()
{
    int base, exp;
    cout << "\nEnter base : ";
    cin >> base;
    cout << "\nEnter exponent : ";
    cin >> exp;
    int ans = power(base, exp);
    cout << "\nAnswer of " << base << " to power " << exp << " is : " << ans << endl;
    return 0;
}