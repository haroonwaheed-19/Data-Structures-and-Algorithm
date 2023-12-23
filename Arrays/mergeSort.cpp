#include <iostream>
using namespace std;
void merge(int *arr, int s, int mid, int e)
{
    int n1 = mid - s + 1;
    int n2 = e - mid;

    int *left, *right;
    left = new int[n1];
    right = new int[n2];

    for (int i = 0; i < n1; i++)
    {
        left[i] = arr[i + s];
    }
    for (int i = 0; i < n2; i++)
    {
        right[i] = arr[i + mid + 1];
    }

    int i = 0, j = 0, k = s;
    while (i < n1 && j < n2)
    {
        if (left[i] < right[j])
        {
            arr[k++] = left[i++];
        }
        else
        {
            arr[k++] = right[j++];
        }
    }
    while (i < n1)
    {
        arr[k++] = left[i++];
    }
    while (j < n2)
    {
        arr[k++] = right[j++];
    }
    delete[] left;
    delete[] right;
    right = NULL;
    left = NULL;
}
void mergeSort(int *arr, int s, int e)
{
    if (s >= e)
    {
        return;
    }

    int mid = s + ((e - s) / 2);
    mergeSort(arr, s, mid);
    mergeSort(arr, mid + 1, e);
    merge(arr, s, mid, e);
}
int main()
{
    int n = 8;
    int arr[] = {10, 28, 24, 6, 34, 18, 38, 44};
    cout << "\nBefore Sorting" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "\nAfter Sorting" << endl;
    mergeSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}