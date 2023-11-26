#include <iostream>
using namespace std;

// function for partition
int partition(int *arr, int s, int e)
{
    int pivot = arr[s]; // Choose the first element as the pivot
    int i = s + 1;      // Index of the smaller element

    for (int j = s + 1; j <= e; j++)
    {
        if (arr[j] < pivot)
        {
            swap(arr[i], arr[j]);
            i++;
        }
    }

    // Swap the pivot element to its correct position
    swap(arr[s], arr[i - 1]);

    return i - 1; // Return the index of the pivot element
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
    int n1 = 12, n2 = 7;
    int arr[n1] = {57, 85, 100, 2, 4, 6, 1, 9, 9, 9, 10, 25};
    int arr1[n2] = {10, 80, 30, 90, 40, 50, 70};
    cout << "\n\t\tOriginal array 1" << endl;
    print(arr, n1);
    quickSort(arr, 0, n1 - 1);
    cout << "\n\t\tAfter Quick Sort" << endl;
    print(arr, n1);
    cout << "\n\t\tOriginal array 2" << endl;
    print(arr1, n2);
    quickSort(arr1, 0, n2 - 1);
    cout << "\n\t\tAfter Quick Sort" << endl;
    print(arr1, n2);
    return 0;
}