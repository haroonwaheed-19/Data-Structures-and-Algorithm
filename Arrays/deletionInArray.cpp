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
void deleteAtSpecific(int *arr, int &n, int index)
{
    int j = index;
    while (j < n - 1)
    {
        arr[j] = arr[j + 1];
        j++;
    }
    n--;
}
int main()
{
    int n = 6;
    int arr[n] = {2, 5, 10, 15, 52,60};
    print(arr, n);
    cout << "\n\t\tAfter Deletion" << endl;
    deleteAtSpecific(arr, n, 3);
    print(arr, n);
    return 0;
}