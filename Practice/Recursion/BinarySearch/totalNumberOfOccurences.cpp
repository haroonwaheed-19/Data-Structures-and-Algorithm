#include <iostream>
using namespace std;

int firstOccurrence(int *arr, int s, int e, int key)
{
    // base case
    if (s > e)
    {
        return -1;
    }

    int mid = s + ((e - s) / 2);
    if (arr[mid] == key)
    {
        // Update ans and continue searching in the left half
        int leftResult = firstOccurrence(arr, s, mid - 1, key);
        if (leftResult != -1)
        {
            return leftResult;
        }
        else
        {
            return mid;
        }
    }
    else if (key > arr[mid])
    {
        return firstOccurrence(arr, mid + 1, e, key);
    }
    else
    {
        return firstOccurrence(arr, s, mid - 1, key);
    }
}

int lastOccurrence(int *arr, int s, int e, int key)
{
    // base case
    if (s > e)
    {
        return -1;
    }

    int mid = s + ((e - s) / 2);
    if (arr[mid] == key)
    {
        // Update ans and continue searching in the right half
        int rightResult = lastOccurrence(arr, mid + 1, e, key);
        if (rightResult != -1)
        {
            return rightResult;
        }
        else
        {
            return mid;
        }
    }
    else if (key > arr[mid])
    {
        return lastOccurrence(arr, mid + 1, e, key);
    }
    else
    {
        return lastOccurrence(arr, s, mid - 1, key);
    }
}

int main()
{
    int n = 12;
    int arr[n] = {10, 10, 16, 16, 16, 19, 19, 19, 19, 21, 21, 25};
    int s = 0, e = n - 1;
    int key;
    cout << "Enter key : ";
    cin >> key;

    int ans1 = firstOccurrence(arr, s, e, key);
    cout << "\nFirst occurrence of " << key << " is at index : " << ans1 << endl;

    int ans2 = lastOccurrence(arr, s, e, key);
    cout << "\nLast occurrence of " << key << " is at index : " << ans2 << endl;

    int totalOccurences = (ans2 - ans1) + 1;
    cout << "\nTotal occurences of " << key << " is " << totalOccurences << endl;
    return 0;
}
