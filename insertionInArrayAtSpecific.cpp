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
void insertAtSpecific(int *arr, int &n, int index, int key)
{
    int j = n - 1;
    n = n + 1;
    while (j >=index)
    {
        arr[j + 1] = arr[j];
        j--;
    }
    arr[index] = key;
}
int main()
{
    int n = 5;
    int arr[n] = {2, 5, 10, 15, 52};
    print(arr, n);
    cout << "\n\t\tAfter Insertion" << endl;
    insertAtSpecific(arr, n, 3, 12);
    print(arr, n);// 2 5 10 12 15 52
    return 0;
}