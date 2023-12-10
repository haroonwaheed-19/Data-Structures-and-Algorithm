#include <iostream>
using namespace std;
bool isPossible(int *arr, int n, int m, int mid)
{
    int studentCount = 1;
    int pageSum = 0;

    for (int i = 0; i < n; i++)
    {
        if (pageSum + arr[i] <= mid)
        {
            pageSum += arr[i];
        }
        else
        {
            studentCount++;
            if (studentCount > m || arr[i] > mid)
            {
                return false;
            }
            else
            {
                pageSum = arr[i];
            }
        }
    }
    return true;
}
int allocateBooksUtil(int *arr, int n, int m, int s, int e)
{
    if (s > e)
    {
        return -1;
    }

    int mid = s + ((e - s) / 2);

    if (isPossible(arr, n, m, mid))
    {
        int ans = allocateBooksUtil(arr, n, m, s, mid - 1);
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
        return allocateBooksUtil(arr, n, m, mid + 1, e);
    }
}

int allocateBooks(int *arr, int n, int m)
{
    int s = 0;
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    int e = sum;

    return allocateBooksUtil(arr, n, m, s, e);
}

int main()
{
    int n = 4;
    int arr[n] = {10, 20, 30, 40};
    int ans = allocateBooks(arr, n, 2);
    cout << ans << endl;
    return 0;
}
