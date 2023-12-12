#include <iostream>
using namespace std;

void bubbleSort(int *arr, int n)
{
    if (n == 0 || n == 1)
    {
        return;
    }

    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            swap(arr[i], arr[i + 1]);
        }
    }
    bubbleSort(arr, n - 1);
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
    bubbleSort(arr, n);
    cout << "\nAfter Sorting" << endl;
    printArray(arr, n);
    return 0;
}