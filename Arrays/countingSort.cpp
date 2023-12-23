#include <iostream>
#include <vector>
using namespace std;
void countSort(vector<int> &v)
{
    int n = v.size();
    // finding maximum element in array
    int maxi = INT16_MIN;
    for (int i = 0; i < n; i++)
    {
        maxi = max(v[i], maxi);
    }
    // finding the frequency of the elements
    vector<int> freq(maxi + 1, 0);
    for (int i = 0; i < n; i++)
    {
        freq[v[i]]++;
    }
    // Print frequency array before cumulative sum
    cout << "Frequency array before cumulative sum:" << endl;
    for (int i = 0; i <= maxi; i++)
    {
        cout << freq[i] << " ";
    }
    cout << endl;
    // finding cumulative sum
    for (int i = 1; i <= maxi; i++)
    {
        freq[i] += freq[i - 1];
    }
    // Print frequency array after cumulative sum
    cout << "Frequency array after cumulative sum:" << endl;
    for (int i = 0; i <= maxi; i++)
    {
        cout << freq[i] << " ";
    }
    cout << endl;
    // sorting the array
    vector<int> ans(n, 0);
    for (int i = n - 1; i >= 0; i--)
    {
        int key = v[i];
        int pos = freq[key] - 1;
        ans[pos] = key;
        freq[key]--;
    }
    // copying the element back to the original array
    for (int i = 0; i < n; i++)
    {
        v[i] = ans[i];
    }
    // printing the array
    cout << "Sorted Array:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n = 5;
    vector<int> arr(n);
    // taking input from user
    cout << "\nEnter the element in the array" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    countSort(arr);
    return 0;
}