#include <iostream>
using namespace std;

void selectionSort(int *arr, int n)
{
    if (n == 0 || n == 1)
    {
        return;
    }

    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i + 1] < arr[i])
        {
            swap(arr[i + 1], arr[i]);
        }
    }
    selectionSort(arr, n - 1);
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
    int n = 5;
    int arr[n] = {2, 1, 6, 8, 5};
    cout << "\nBefore Sorting" << endl;
    printArray(arr, n);
    selectionSort(arr, n);
    cout << "\nAfter Sorting" << endl;
    printArray(arr, n);
    return 0;
}