#include <iostream>
using namespace std;

int sumOfElements(int *arr, int n)
{
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return arr[0];
    }

    int sum = arr[0] + arr[1];

    return sum + sumOfElements(arr + 2, n - 2);
}
int main()
{
    int n = 6;
    int arr1[n] = {21, 29, 100, 55, 185, 25};
    int ans = sumOfElements(arr1, n);
    cout << "\nSum is : " << ans << endl;
    return 0;
}