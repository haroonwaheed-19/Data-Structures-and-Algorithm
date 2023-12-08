#include <iostream>
using namespace std;
void printCount(int n)
{
    // base case
    if (n == 0)
    {
        return;
    }
    // head recursion
    printCount(n - 1);
    // printing numbers
    cout << n << " ";
}
int main()
{
    int n = 10;
    printCount(n);
    return 0;
}