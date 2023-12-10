#include <iostream>
using namespace std;
int getPivot(int *arr, int s, int e, int n)
{
    // pivot element is the element which is largest in the array and after that all elements are smaller and it is in ascending order
    if (s >= e)
    {
        return -1;
    }
    int mid = s + ((e - s) / 2);
    if (arr[mid] >= arr[0])
    {
        int ans = getPivot(arr, mid + 1, e, n);
        cout << "ans : " << arr[ans] << endl;
        return ans - 1;
    }
    else
    {
        getPivot(arr, s, mid, n);
        cout << "mid : " << arr[mid - 1] << endl;
        return mid - 1;
    }
}
int main()
{
    int n = 14;
    int s = 0, e = n - 1;
    int arr[n] = {8, 9, 10, 11, 12, 13, 16, 19, 21, 3, 4, 5, 6, 7};
    int ans = getPivot(arr, s, e, n);
    cout << "\npivot Element is at index " << ans << " and it is : " << arr[ans] << endl;

    return 0;
}