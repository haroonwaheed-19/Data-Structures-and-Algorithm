#include <iostream>
using namespace std;

long long int squareRoot(int s, int e, int n)
{
    // base case
    if (s > e)
    {
        return e;
    }

    long long int mid = s + ((e - s) / 2);

    long long int sq = mid * mid;
    if (sq == n)
    {
        return mid;
    }

    if (sq < n)
    {
        return squareRoot(mid + 1, e, n); // Capture the result of the recursive call
    }
    else
    {
        return squareRoot(s, mid - 1, n); // Capture the result of the recursive call
    }
}
double precision(int n, int precision, int temp)
{
    double factor = 1;
    double result = temp;
    for (int i = 0; i < precision; i++)
    {
        factor = factor / 10;
        for (double j = result; j * j < n; j += factor)
        {
            result = j;
        }
    }
    return result;
}
int main()
{
    int n;
    cout << "\nEnter the number to find square root : ";
    cin >> n;
    int tempAns = squareRoot(0, n, n);
    double ans = precision(n, 3, tempAns);
    cout << "\nsquare root of " << n << " is : " << ans << endl;

    return 0;
}
