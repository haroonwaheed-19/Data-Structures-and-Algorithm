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

void selectionSort(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        // finding minimum element index
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        // swapping when min and i have different values if same no need to swap they already in place
        if (i != min)
        {
            int temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
        }
    }
}

int main()
{
    int n = 6;
    int arr[n] = {15, 5, 98, 52, 2, 10};
    cout << "\n\t\tOriginal array" << endl;
    print(arr, n);
    selectionSort(arr, n);
    cout << "\n\t\tAfter selection Sort" << endl;
    print(arr, n);

    return 0;
}