#include <iostream>
using namespace std;

// factorial Function
int factorial(int n)
{
    if (n == 0)
    {
        return 1;
    }

    return n * factorial(n - 1);
}
int main()
{
    int n;
    cout << "Enter a number to find factorial : ";
    cin >> n;
    int ans = factorial(n);
    cout << "\nFactorial is : " << ans << endl;
    return 0;
}