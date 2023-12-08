#include <iostream>
using namespace std;
int power(int b, int e)
{
    if (e == 0)
    {
        return 1;
    }
    return b * power(b, e - 1);
}
int main()
{
    int base, exp;
    cout << "Enter a base : ";
    cin >> base;
    cout << "Enter an exponent : ";
    cin >> exp;
    int ans = power(base, exp);
    cout << "\nThe Answer of " << base << " to the power " << exp << " is : " << ans << endl;
    return 0;
}