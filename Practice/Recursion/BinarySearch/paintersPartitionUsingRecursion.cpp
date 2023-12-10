#include <iostream>
using namespace std;
bool isPossible(int *arr, int n, int k, int mid)
{
    int painter = 1;
    int unit = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] + unit <= mid)
        {
            unit += arr[i];
        }
        else
        {
            painter++;
            if (painter > k || arr[i] > mid)
            {
                return false;
            }
            else
            {
                unit = arr[i];
            }
        }
    }
    return true;
}
int paintBoardsUtil(int *arr, int n, int k, int s, int e)
{
    if (s > e)
    {
        return -1;
    }

    int mid = s + ((e - s) / 2);

    if (isPossible(arr, n, k, mid))
    {
        int ans = paintBoardsUtil(arr, n, k, s, mid - 1);
        if (ans != -1)
        {
            return ans;
        }
        else
        {
            return mid;
        }
    }
    else
    {
        return paintBoardsUtil(arr, n, k, mid + 1, e);
    }
}
int paintersPartition(int *arr, int n, int k)
{
    int s = 0;
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    int e = sum;

    return paintBoardsUtil(arr, n, k, s, e);
}
int main()
{
    int n = 6;
    int arr[n] = {2, 1, 5, 6, 2, 3};
    int k = 2;
    int ans = paintersPartition(arr, n, k);
    cout << ans << endl;
    return 0;
}