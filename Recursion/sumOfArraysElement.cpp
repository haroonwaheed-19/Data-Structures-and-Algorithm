#include <iostream>
using namespace std;
void print(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}
int getSum(int *arr, int size)
{
    if (size <= 0)
    {
        return 0;
    }
    if (size == 1)
    {
        return arr[0];
    }
    return arr[size - 1] + getSum(arr, size - 1);
}
int main()
{
    int size = 6;
    int arr[size] = {3, 2, 5, 1, 6, 10};
    int arr1[size-1] = {3, 2, 5, 1, 6};
    print(arr, size);
    cout << "\nSum of array elements is " << getSum(arr, size) << " in case of even size" << endl;
    print(arr1, size-1);
    cout << "\nSum of array elements is " << getSum(arr1, size-1) << " in case of odd size" << endl;
    return 0;
}