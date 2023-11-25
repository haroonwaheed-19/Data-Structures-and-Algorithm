#include <iostream>
using namespace std;

bool isPresent(int *arr, int size, int key)
{
    if (size == 0)
    {
        return 0;
    }
    if (arr[0] == key)
    {
        return true;
    }
    else
    {
        return isPresent(arr + 1, size - 1, key);
    }
}
int main()
{
    int size = 6;
    int key = 1;
    int arr[size] = {13, 2, 15, 1, 6, 10};
    int ans = isPresent(arr, size, key);
    if (ans)
    {
        cout << "\n"
             << key << " is present" << endl;
    }
    else
    {
        cout << "\n"
             << key << " is not present" << endl;
    }
    return 0;
}