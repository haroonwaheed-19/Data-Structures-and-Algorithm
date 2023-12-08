#include <iostream>
using namespace std;
int climbStairs(int n)
{
    if (n < 0)
    {
        return 0;
    }
    if (n == 0)
    {
        return 1;
    }

    int ans = climbStairs(n - 1) + climbStairs(n - 2);
    return ans;
}
int main()
{
    int n;
    cout << "Enter the number of stairs : ";
    cin >> n;
    int ans = climbStairs(n);
    cout << "\nThe distinct way/steps to reach " << n << "th stairs is : " << ans << endl;
    return 0;
}