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

void transpose(int trans[][n], int arr[][n], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            trans[j][i] = arr[i][j];
        }
    }
}
int main()
{
    int arr[n][n] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int trans[n][n] = {0};
    displayArray(arr, n);
    transpose(trans, arr, n);
    cout << "\nAfter transposing ";
    displayArray(trans, n);
    return 0;
}