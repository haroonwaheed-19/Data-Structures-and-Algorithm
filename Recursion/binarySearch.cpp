#include <iostream>
using namespace std;
void print(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}
bool binarySearch(int *arr, int s, int e, int key)
{
    // Base case
    if (s > e)
    {
        return false;
    }
    int mid = s + ((e - s) / 2);
    if (arr[mid] == key)
    {
        return true;
    }
    // right half when key>arr[mid]
    if (key > arr[mid])
    {
        return binarySearch(arr, mid + 1, e, key);
    }
    else
    {
        // key<arr[mid]
        return binarySearch(arr, s, mid - 1, key);
    }
}
int main()
{
    int size = 6;
    int key = 67;
    int s = 0, e = size - 1;
    int arr[size] = {10, 23, 35, 48, 55, 67};
    int ans = binarySearch(arr, s, e, key);
    print(arr, size);
    if (ans)
    {
        cout << "\n"
             << key << " is present" << endl;
    }
    else
    {
        cout << "\n"
             << key << " is not present" << endl;
    }
    return 0;
}