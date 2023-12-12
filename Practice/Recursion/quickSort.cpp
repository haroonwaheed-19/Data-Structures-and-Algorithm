#include <iostream>
using namespace std;
void printArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int partition(int *arr, int s, int e)
{
    int pivot = arr[s];
    int count = 0;
    for (int i = s + 1; i <= e; i++)
    {
        if (arr[i] <= pivot)
        {
            count++;
        }
    }
    // correct index for the pivot
    int pivotIndex = s + count;
    // swapping the pivot element at its right place
    swap(arr[pivotIndex], arr[s]);
    // now staisfying the both side of the pivot element
    int i = 0, j = e;
    while (i < pivotIndex && j > pivotIndex)
    {
        // move the iterator if all the elements are lesser than the pivot element
        while (arr[i] <= pivot)
        {
            i++;
        }
        // move the iterator if all the elements are greater than the pivot element
        while (arr[j] > pivot)
        {
            j--;
        }
        // now placing the element at the right place
        if (i < pivotIndex && j > pivotIndex)
        {
            swap(arr[i++], arr[j--]);
        }
    }
    return pivotIndex;
}
void quickSort(int *arr, int s, int e)
{
    if (s >= e)
    {
        return;
    }

    int p = partition(arr, s, e);
    // recursive call for left part
    quickSort(arr, s, p - 1);
    // for right part
    quickSort(arr, p + 1, e);
}
int main()
{
    int n = 16;
    int arr[n] = {3, 7, 0, 1, 5, 8, 3, 2, 24, 66, 87, 23, 12, 12, 12, 69};
    cout << "\nBefore Sorting" << endl;
    printArray(arr, n);
    quickSort(arr, 0, n - 1);
    cout << "\nAfter Sorting" << endl;
    printArray(arr, n);
    return 0;
}