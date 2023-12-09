#include <iostream>
using namespace std;
int peekElement(int *arr, int s, int e, int n)
{
    if (s >= e)
    {
        return -1;
    }

    int mid = (s + (e - s) / 2);

    // Check for repeated elements
    if (mid > 0 && arr[mid] == arr[mid - 1])
    {
        // Check left side
        while (mid > 0 && arr[mid] == arr[mid - 1])
        {
            mid--;
        }
    }
    if (mid < n - 1 && arr[mid] == arr[mid + 1])
    {
        // Check right side
        while (mid < n - 1 && arr[mid] == arr[mid + 1])
        {
            mid++;
        }
    }

    // Compare with neighbors
    if (mid == 0 || arr[mid] > arr[mid - 1])
    {
        if (mid == n - 1 || arr[mid] > arr[mid + 1])
        {
            return mid;
        }
        else
        {
            // Peak might be on the right
            return peekElement(arr, mid + 1, e, n);
        }
    }
    else
    {
        // Peak might be on the left
        return peekElement(arr, s, mid - 1, n);
    }
}

int main()
{
    int n = 7, n2 = 5;
    int arr[n] = {10, 16, 19, 21, 14, 11, 9};
    int arr1[n2] = {3, 4, 5, 6, 2};
    int s = 0, e = n - 1;
    int s1 = 0, e1 = n2 - 1;
    int ans1 = peekElement(arr, s, e, n);
    int ans2 = peekElement(arr1, s1, e1, n2);
    cout << arr[ans1] << endl;
    cout << arr1[ans2] << endl;
    return 0;
}
