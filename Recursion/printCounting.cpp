#include <iostream>
using namespace std;

void print(int n)
{
    // base case
    if (n == 0)
    {
        return;
    }
    cout << n << " ";
    // recirsive call(tail recursion)
    print(n - 1);
}
int main()
{
    int n; // 5
    cout << "\nEnter a number : ";
    cin >> n;
    cout << endl;
    print(n); // 5 4 3 2 1
    return 0;
}