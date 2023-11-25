#include <iostream>
using namespace std;
void print(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}
bool isSortedAscending(int *arr1, int size)
{
    // base case
    if (size == 0 || size == 1) // if there is no element or 1 in the array they are sorted
    {
        return true;
    }

    if (arr1[0] > arr1[1])
    {
        return false;
    }
    else
    {
        // recursive call
        return isSortedAscending(arr1 + 1, size - 1);
    }
}
bool isSortedDescending(int *arr2, int size)
{
    // base case
    if (size == 0 || size == 1) // if there is no element or 1 in the array they are sorted
    {
        return true;
    }

    if (arr2[0] < arr2[1])
    {
        return true;
    }
    else
    {
        // recursive call
        return isSortedDescending(arr2 + 1, size - 1);
    }
}
int main()
{
    int size = 6;
    int arr1[size] = {2, 4, 5, 8, 19, 19};
    int arr2[size] = {19, 15, 12, 10, 8, 6};
    bool ans = isSortedAscending(arr1, size);
    bool ans1 = isSortedDescending(arr2, size);
    cout << "\n\t\tArray 1" << endl;
    print(arr1, size);
    if (ans)
    {
        cout << "\nArray 1 is Sorted in Ascending Order" << endl;
    }
    else
    {
        cout << "\nArray 1 is not Sorted in Ascending Order" << endl;
    }
    cout << "\n\t\tArray 2" << endl;
    print(arr2, size);
    if (ans1)
    {
        cout << "\nArray 2  is Sorted in Descending Order" << endl;
    }
    else
    {
        cout << "\nArray 2 is not Sorted in Descending Order" << endl;
    }
    return 0;
}