#include <iostream>
using namespace std;
int getPivot(int *arr, int s, int e, int n)
{
    // pivot element is the element which is largest in the array and after that all elements are smaller and it is in ascending order
    if (s >= e)
    {
        return -1;
    }
    int mid = s + ((e - s) / 2);
    if (arr[mid] >= arr[0])
    {
        int ans = getPivot(arr, mid + 1, e, n);
        return ans - 1;
    }
    else
    {
        getPivot(arr, s, mid, n);
        return mid - 1;
    }
}
int binarySearch(int *arr, int s, int e, int key)
{

    // base case
    if (s > e)
    {
        return -1;
    }

    int mid = s + ((e - s) / 2);
    if (arr[mid] == key)
    {
        return mid;
    }

    if (key > arr[mid])
    {
        return binarySearch(arr, mid + 1, e, key);
    }
    else
    {
        return binarySearch(arr, s, mid - 1, key);
    }
}
void printArray(int *arr, int n)
{
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    int n = 14;
    int s = 0, e = n - 1;
    int arr[n] = {8, 9, 10, 11, 12, 13, 16, 19, 21, 3, 4, 5, 6, 7};
    int pivot = getPivot(arr, s, e, n);
    int key;
    cout << "\nEnter the number you want to find : ";
    cin >> key;
    if (key >= arr[0] && key <= arr[pivot])
    {
        int ans = binarySearch(arr, s, pivot, key);
        printArray(arr, n);
        if (ans != -1)
        {
            cout << key << " Found " << endl;
        }
        else
        {
            cout << key << " Not Found " << endl;
        }
    }
    else
    {
        int ans = binarySearch(arr, pivot + 1, e, key);
        printArray(arr, n);
        if (ans != -1)
        {
            cout << key << " Found " << endl;
        }
        else
        {
            cout << key << " Not Found " << endl;
        }
    }

    return 0;
}