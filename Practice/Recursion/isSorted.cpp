#include <iostream>
#include <string>
using namespace std;

bool isSortedAscending(int *arr, int n)
{
    if (n == 0 || n == 1)
    {
        return true;
    }

    if (arr[0] > arr[1])
    {
        return false;
    }
    else
    {
        return isSortedAscending(arr + 1, n - 1);
    }
}

void printArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    int n = 6;
    int arr1[n] = {21, 29, 100, 55, 185, 25};
    int arr2[n] = {21, 29, 37, 55, 85, 125};
    if (isSortedAscending(arr1, n))
    {
        cout << "\nArray 1 is Sorted" << endl;
    }
    else
    {
        cout << "\nArray 1 is Not sorted" << endl;
    }
    printArray(arr1, n);
    if (isSortedAscending(arr2, n))
    {
        cout << "\nArray 2 is Sorted" << endl;
    }
    else
    {
        cout << "\nArray 2 is Not sorted" << endl;
    }
    printArray(arr2, n);
    return 0;
}