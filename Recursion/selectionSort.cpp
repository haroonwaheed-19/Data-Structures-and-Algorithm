#include <iostream>
using namespace std;
void print(int *arr, int n)
{
    cout << "\n\tElements in the array are : ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void selectionSort(int *arr, int n, int i)
{
    // base case
    if (i == n - 1)
    {
        return;
    }
    if (n == 0 || n == 1)
    {
        return;
    }
    // solving one case
    int min = i;
    for (int j = i + 1; j < n; j++)
    {
        // finding minnimum index
        if (arr[j] < arr[min])
        {
            min = j;
        }
    }
    // swapping the indices values
    if (i != min)
    {
        swap(arr[i], arr[min]);
    }
    // Recursive call
    selectionSort(arr, n, i + 1);
}

int main()
{
    int n = 6;
    int arr[n] = {15, 5, 98, 52, 2, 10};
    cout << "\n\t\t\tOriginal array" << endl;
    print(arr, n);
    selectionSort(arr, n, 0);
    cout << "\n\t\t\tAfter selection Sort" << endl;
    print(arr, n);

    return 0;
}