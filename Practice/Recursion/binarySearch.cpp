#include <iostream>
using namespace std;
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
int main()
{
    int n = 5;
    int *arr = new int[n];
    int s = 0, e = n - 1;
    int key;
    cout << "Enter key : ";
    cin >> key;
    // Initialize the array using a loop
    int initialValues[] = {10, 16, 19, 21, 25};
    for (int i = 0; i < n; i++)
    {
        arr[i] = initialValues[i];
    }

    // Print the array elements
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    int ans = binarySearch(arr, s, e, key);

    if (ans == -1)
    {
        cout << "\n"
             << key << " not present" << endl;
    }
    else
    {
        cout << "\n"
             << key << " present in the array at index " << ans + 1 << endl;
    }

    delete[] arr;

    return 0;
}
