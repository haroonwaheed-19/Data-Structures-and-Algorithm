#include <iostream>
using namespace std;

int factorial(int n)
{
    int fact = 1;
    while (n != 0)
    {
        fact = fact * n;
        n--;
    }
    return fact;
}

int sumOfFactorial(int n)
{
    int sum = 0;
    for (int i = n; i >= 1; i--)
    {
        sum += factorial(i);
    }
    return sum;
}

int main()
{
    int n = 5;
    int ans = factorial(n);
    cout << "\nFactorial is " << ans << endl; // 120
    int sum = sumOfFactorial(n);
    cout << "\nSum of Factorial from " << n << " to 1 is " << sum << endl; // 153
    return 0;
}
