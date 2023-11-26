#include <iostream>
using namespace std;
int calculatePower(int a, int b)
{
    // base case
    if (b == 0) // when power is 0 return 1
    {
        return 1;
    }
    if (b == 1) // return a(base) when power is 1
    {
        return a;
    }
    // dividing the power into half and calculating power for that power
    int ans = calculatePower(a, b / 2); // Recursive call
    // when power is even
    if (b % 2 == 0)
    {
        return ans * ans;
    }
    else
    {
        // power is odd
        return a * ans * ans;
    }
}
int main()
{
    int a, b;
    cout << "\n\tEnter Base : ";
    cin >> a;
    cout << "\n\tEnter Power : ";
    cin >> b;
    // a is base, b is exponent
    int ans = calculatePower(a, b);
    cout << "\n\n"
         << a << " to power of " << b << " is : " << ans << endl;
    return 0;
}