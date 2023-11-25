#include <iostream>
using namespace std;
const int n = 3;
void displayArray(int arr[][n], int n)
{
    cout << "\n\t\tElements in the array" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void sumAndProduct(int arr[][n], int n, int &sum, int &prod)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                sum = sum + arr[i][j];
            }
            if (i == j && arr[i][j] != 0)
            {
                prod = prod * arr[i][j];
            }
        }
    }
}
int main()
{
    int sum = 0;
    int prod = 1;
    int arr[n][n] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    displayArray(arr, n);
    sumAndProduct(arr, n, sum, prod);
    cout << "\nSum of Diagonal values " << sum << endl;
    cout << "\nproduct of Diagonal values " << prod << endl;
    return 0;
}