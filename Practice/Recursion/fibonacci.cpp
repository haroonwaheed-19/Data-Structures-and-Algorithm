#include <iostream>
using namespace std;
int fibonacci(int n)
{
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }

    int ans = fibonacci(n - 1) + fibonacci(n - 2);
    return ans;
}
int main()
{
    int n = 7;
    int ans = fibonacci(n);
    cout << n << " fibonacci number is : " << ans << endl;
    return 0;
}