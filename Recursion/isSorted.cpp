#include <iostream>
using namespace std;
bool isSorted(int *arr, int size)
{
    // base case
    if (size == 0 || size == 1) // if there is no element or 1 in the array they are sorted
    {
        return true;
    }

    if (arr[0] > arr[1])
    {
        return false;
    }
    else
    {
        // recursive call
        return isSorted(arr + 1, size - 1);
    }
}
int main()
{
    int size = 6;
    int arr1[size] = {2, 4, 5, 8, 19, 19};
    int arr2[size] = {2, 4, 0, 8, 29, 19};
    bool ans = isSorted(arr1, size);
    bool ans1 = isSorted(arr2, size);
    if (ans)
    {
        cout << "\nArray 1 is Sorted" << endl;
    }
    else
    {
        cout << "\nArray 1 is not Sorted" << endl;
    }
    if (ans1)
    {
        cout << "\nArray 2  is Sorted" << endl;
    }
    else
    {
        cout << "\nArray 2 is not Sorted" << endl;
    }
    return 0;
}