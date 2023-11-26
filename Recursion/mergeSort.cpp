#include <iostream>
using namespace std;
void merge(int *arr, int s, int e)
{

    int mid = s + ((e - s) / 2);
    // length for 2 arrays
    int len1 = mid - s + 1;
    int len2 = e - mid;
    // creating new arrays
    int *left = new int[len1];
    int *right = new int[len2];

    // copying values into arrays
    int mainIndex = s;
    for (int i = 0; i < len1; i++)
    {
        left[i] = arr[mainIndex++];
    }
    mainIndex = mid + 1;
    for (int i = 0; i < len2; i++)
    {
        right[i] = arr[mainIndex++];
    }

    // merging 2 sorted arrays
    int index1 = 0, index2 = 0;
    mainIndex = s;
    while (index1 < len1 && index2 < len2)
    {
        if (left[index1] < right[index2])
        {
            arr[mainIndex++] = left[index1++];
        }
        else
        {
            arr[mainIndex++] = right[index2++];
        }
    }
    while (index1 < len1)
    {
        arr[mainIndex++] = left[index1++];
    }
    while (index2 < len2)
    {
        arr[mainIndex++] = right[index2++];
    }
    delete[] left;
    delete[] right;
}
void mergeSort(int *arr, int s, int e)
{
    if (s >= e)
    {
        return;
    }

    int mid = s + ((e - s) / 2);
    // left part recursive call
    mergeSort(arr, s, mid);
    // right part recursive call
    mergeSort(arr, mid + 1, e);
    // merge
    merge(arr, s, e);
}
void print(int *arr, int n)
{
    cout << "\nElements in the array are : ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    int n = 6;
    int arr[n] = {15, 5, 98, 52, 2, 10};
    cout << "\n\t\tOriginal array" << endl;
    print(arr, n);
    mergeSort(arr, 0, n - 1);
    cout << "\n\t\tAfter Merge Sort" << endl;
    print(arr, n);
    return 0;
}