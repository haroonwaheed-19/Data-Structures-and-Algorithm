#include <iostream>
using namespace std;

int peekElement(int *arr, int s, int e, int n)
{
    if (s >= e)
    {
        return -1;
    }

    int mid = (s + (e - s) / 2);
    if (arr[mid] < arr[mid + 1])
    {
        peekElement(arr, mid + 1, e, n);
        return mid + 1;
    }
    else
    {
        peekElement(arr, s, mid, n);
        return mid;
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
    int n = 8, n2 = 10;
    int arr[n] = {10, 16, 19, 21, 25, 14, 11, 9};
    int arr1[n2] = {3, 4, 5, 6, 10, 13, 5, 3, 2, 1};
    int s = 0, e = n - 1;
    int s1 = 0, e1 = n2 - 1;
    int ans1 = peekElement(arr, s, e, n);
    int ans2 = peekElement(arr1, s1, e1, n2);
    printArray(arr, n);
    cout << "\nPeek Element in the array 1 is : " << arr[ans1] << endl;
    printArray(arr1, n2);
    cout << "\nPeek Element in the array 2 is : " << arr1[ans2] << endl;
    return 0;
}
