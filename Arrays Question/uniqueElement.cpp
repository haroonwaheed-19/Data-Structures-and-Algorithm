#include <iostream>
using namespace std;

int main()
{
    int arr[] = {1, 3, 1, 2, 50, 3, 2, 10, 10, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int max = arr[0];

    // Find the maximum element in the array
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    // Create an array to count occurrences of each element
    int arr1[max + 1] = {0};
    for (int i = 0; i < n; i++)
    {
        arr1[arr[i]]++;
    }

    int unique = 0;
    bool check = false;
    // Find the unique element
    for (int i = 0; i <= max; i++)
    {
        if (arr1[i] == 1)
        {
            unique = i;
            check = true;
            break; // Stop searching once a unique element is found
        }
    }
    if (check)
    {
        cout << "The unique element is: " << unique << endl;
    }
    else
    {
        cout << "NO unique element" << endl;
    }
    return 0;
}