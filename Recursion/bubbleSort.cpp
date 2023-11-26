#include <iostream>
using namespace std;
void print(int *arr, int n)
{
    cout << "\n\tElements in the array are : ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void bubbleSortAscending(int *arr, int n)
{
    if (n == 0 || n == 1)
    {
        return;
    }
    // soling the one case other case will handle by recursion
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            swap(arr[i], arr[i + 1]);
        }
    }

    // recursive call
    bubbleSortAscending(arr, n - 1);
}
void bubbleSortDescending(int *arr, int n)
{
    if (n == 0 || n == 1)
    {
        return;
    }
    // soling the one case other case will handle by recursion
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] < arr[i + 1])
        {
            swap(arr[i], arr[i + 1]);
        }
    }

    // recursive call
    bubbleSortDescending(arr, n - 1);
}
int main()
{
    int n = 6;
    int arr[n] = {15, 5, 98, 52, 2, 10};
    int arr1[n] = {15, 5, 98, 52, 2, 10};

    cout << "\n\t\t\tOriginal array" << endl;
    print(arr, n);

    bubbleSortAscending(arr, n);
    cout << "\n\t\tAfter bubble Sort in ascending Order" << endl;
    print(arr, n);

    cout << "\n\t\tAfter bubble Sort in descending Order" << endl;
    bubbleSortDescending(arr1, n);
    print(arr1, n);

    return 0;
}