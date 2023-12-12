#include <iostream>
using namespace std;
void printArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int mergeAndCount(int *arr, int s, int e)
{
    int mid = s + ((e - s) / 2);
    // calculating the length for new subarrays
    int len1 = mid - s + 1;
    int len2 = e - mid;
    int count = 0;
    // arryas creation
    int *left = new int[len1];
    int *right = new int[len2];

    // copying the data
    int mainIndex = s;
    for (int i = 0; i < len1; i++)
    {
        left[i] = arr[mainIndex++];
    }
    mainIndex = mid + 1;
    for (int i = 0; i < len2; i++)
    {
        right[i] = arr[mainIndex++];
    }

    // putting the data into main array in sorted order
    int index1 = 0;
    int index2 = 0;
    mainIndex = s;
    while (index1 < len1 && index2 < len2)
    {
        if (left[index1] < right[index2])
        {
            arr[mainIndex++] = left[index1++];
        }
        else
        {
            arr[mainIndex++] = right[index2++];
            count++;
        }
    }

    // copying remaining data form the array if the two arrays are not equal
    while (index1 < len1)
    {
        arr[mainIndex++] = left[index1++];
    }
    while (index2 < len2)
    {
        arr[mainIndex++] = right[index2++];
    }

    // free memory
    free(left);
    free(right);
    return count;
}
int mergeSortAndCount(int *arr, int s, int e)
{
    if (s >= e)
    {
        return -1;
    }
    int invCount = 0;
    int mid = s + ((e - s) / 2);

    // left part sorting
    invCount += (arr, s, mid);

    // right part sorting
    invCount += (arr, mid + 1, e);

    // merge the elements of the array
    invCount += mergeAndCount(arr, s, e);

    return invCount;
}

int main()
{
    int n = 16;
    int i = 1;
    int arr[n] = {3, 7, 0, 1, 5, 8, 3, 2, 24, 66, 87, 23, 12, 12, 12, 69};
    int ans = mergeSortAndCount(arr, 0, n - 1);
    cout << "\nInversion Count is : " << ans << endl;
    return 0;
}
