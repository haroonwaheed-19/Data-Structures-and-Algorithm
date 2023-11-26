#include <iostream>
using namespace std;
// function for partition
int partition(int *arr, int s, int e)
{
    int pivot = arr[s];
    int count = 0;

    // finding the right place for the pivot
    for (int i = s + 1; i <= e; i++)
    {
        if (arr[i] <= pivot)
        {
            count++;
        }
    }

    int pIndex = s + count;
    // swapping the element to place the pivot
    swap(arr[pIndex], arr[s]);

    // sorting the left part and right part
    int i = 0, j = e;

    while (i < pIndex && j > pIndex)
    {
        while (arr[i] <= pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }

        // if arr[i] is not in right place as compared to arr[j]

        if (i < pIndex && j > pIndex)
        {
            swap(arr[i++], arr[j--]);
        }
    }
}
// function for quick sort
void quickSort(int *arr, int s, int e)
{
    // base case
    if (s >= e)
    {
        return;
    }

    // partition
    int p = partition(arr, s, e);

    // solving left part
    quickSort(arr, s, p - 1);
    // solving right part
    quickSort(arr, p + 1, e);
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
    int n = 12;
    int arr[n] = {57, 85, 100, 2, 4, 6, 1, 9, 9, 9, 10, 25};
    cout << "\n\t\tOriginal array" << endl;
    print(arr, n);
    quickSort(arr, 0, n - 1);
    cout << "\n\t\tAfter Quick Sort" << endl;
    print(arr, n);
    return 0;
}