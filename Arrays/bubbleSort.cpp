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

// ascending order sort
void bubbleSortAscending(int *arr, int n)
{
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
// descending order sorting
void bubbleSortDescending(int *arr1, int n)
{
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr1[j] < arr1[j + 1])
            {
                int temp = arr1[j + 1];
                arr1[j + 1] = arr1[j];
                arr1[j] = temp;
            }
        }
    }
}

int main()
{
    int n = 6;
    int arr[n] = {15, 5, 98, 52, 2, 10};
    int arr1[n] = {15, 5, 98, 52, 2, 10};
    cout << "\n\t\tOriginal array" << endl;
    print(arr, n);
    bubbleSortAscending(arr, n);
    cout << "\n\t\tAfter bubble Sort in ascending Order" << endl;
    print(arr, n);
    cout << "\n\t\tAfter bubble Sort in descending Order" << endl;
    bubbleSortDescending(arr1, n);
    print(arr1, n);

    return 0;
}