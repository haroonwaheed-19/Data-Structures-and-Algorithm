#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int arr[] = {-1, 3, -1, 2, 3, 2, 2, 10, 3, 3};
    int n1 = sizeof(arr) / sizeof(arr[0]);

    const int n = 2001;
    const int shift = 1000;
    vector<int> arr1(n, 0);
    // Use the size of arr in the loop condition
    for (int i = 0; i < n1; i++)
    {
        arr1[arr[i] + shift]++;
    }

    // Use the size of arr1 in the loop condition
    vector<int> freq(n, 0);
    for (int i = 0; i < arr1.size(); i++)
    {
        freq[arr1[i]]++;
    }

    // checking the uniqueness of freq array
    bool check = true;
    for (int i = 1; i < freq.size(); i++)
    {
        if (freq[i] > 1)
        {
            check = false;
            break;
        }
    }
    if (check)
    {
        cout << "\nUnique Occurence" << endl;
    }
    else
    {
        cout << "Not a unique occurence" << endl;
    }

    return 0;
}
