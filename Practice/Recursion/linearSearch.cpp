#include <iostream>
using namespace std;
void printArray(int *arr, int n)
{
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

bool linearSearch(int *arr, int n, int key)
{
    if (n == 0)
    {
        return false;
    }
    if (arr[0] == key)
    {
        return true;
    }
    else
    {
        return linearSearch(arr + 1, n - 1, key);
    }
}
int main()
{
    int n = 6;
    int arr1[n] = {21, 29, 100, 55, 185, 25};
    int key;
    cout << "\nEnter key : ";
    cin >> key;
    if (linearSearch(arr1, n, key))
    {
        cout << "\nFound" << endl;
        printArray(arr1, n);
    }
    else
    {
        cout << "\nNot Found" << endl;
        printArray(arr1, n);
    }
    return 0;
}