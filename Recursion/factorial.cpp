#include <iostream>
using namespace std;

// factorial function
int fact(int n)
{
    // base case
    if (n == 0)
    {
        return 1;
    }

    return n * fact(n - 1);
}
int main()
{
    int n;
    cout << "\nEnter a number for which you want to find a factorial : ";
    cin >> n;
    int ans = fact(n);
    cout << "\nFactorial of " << n << " is : " << ans << endl;
    return 0;
}