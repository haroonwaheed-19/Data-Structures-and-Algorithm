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
int paintersPartition(int *arr, int n, int k)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    int s = 0;
    int e = sum;
    int mid = s + ((e - s) / 2);
    int ans = -1;
    while (s <= e)
    {
        if (isPossible(arr, n, k, mid))
        {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
        mid = s + ((e - s) / 2);
    }
    return ans;
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