#include <iostream>
using namespace std;
void print(int *arr, int n)
{
    cout << "\nElements in the array are : ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int binarySearch(int *arr, int n, int key)
{
    int s = 0, e = n - 1;
    int mid = s + ((e - s) / 2);
    while (s <= e)
    {
        if (arr[mid] == key)
        {
            return mid;
        }
        if (key > arr[mid])
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
        mid = s + ((e - s) / 2);
    }
    return -1;
}
int main()
{
    int n = 5;
    int arr[n] = {2, 5, 10, 15, 52};
    int key = 15;
    int check = binarySearch(arr, n, key);
    print(arr, n);
    if (check == -1)
    {
        cout << "\n\tKey " << key << " not present" << endl;
    }
    else
    {
        cout << "\n\tKey " << key << " present at index : " << check << endl;
    }
    return 0;
}