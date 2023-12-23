#include <iostream>
#include <vector>
using namespace std;

void countSort(vector<int> &v, int pos)
{
    int n = v.size();
    vector<int> freq(10, 0);
    // calculating the frequency
    for (int i = 0; i < n; i++)
    {
        freq[(v[i] / pos) % 10]++;
    }
    // cumulative frequency sum
    for (int i = 1; i < 10; i++)
    {
        freq[i] += freq[i - 1];
    }
    // sorting the array
    vector<int> ans(n, 0);
    for (int i = n - 1; i >= 0; i--)
    {
        int key = (v[i] / pos) % 10;
        int index = freq[key] - 1;
        ans[index] = v[i];
        freq[key]--;
    }
    // putting values back into original array
    for (int i = 0; i < n; i++)
    {
        v[i] = ans[i];
    }
}

void radixSort(vector<int> &v)
{
    int n = v.size();
    int maxi = INT32_MIN;
    // calculating maximum numbers
    for (int i = 0; i < n; i++)
    {
        maxi = max(v[i], maxi);
    }
    for (int pos = 1; maxi / pos >= 1; pos *= 10)
    {
        countSort(v, pos);
    }
}

int main()
{
    int n;
    cout << "Enter size: ";
    cin >> n;
    vector<int> arr(n, 0);
    cout << "\nEnter elements:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "\nOriginal Array:";
    for (int i = 0; i < n; i++)
    {
        cout << " " << arr[i];
    }
    cout << endl;
    radixSort(arr);
    cout << "\nSorted Array:";
    for (int i = 0; i < n; i++)
    {
        cout << " " << arr[i];
    }
    cout << endl;
    return 0;
}
