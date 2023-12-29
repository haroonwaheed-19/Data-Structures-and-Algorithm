#include <iostream>
using namespace std;
int main()
{
    int n = 6;
    int arr[n] = {20, 34, 85, 65, 15, 69};
    cout << "\tBefore Swapping" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n - 1; i = i + 2)
    {
        int temp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = temp;
    }
    cout << "\tAfter Swapping" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}