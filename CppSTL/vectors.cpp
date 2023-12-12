#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    cout << "\nSize is :" << v.size() << endl;
    cout << "\nCapacity is :" << v.capacity() << endl;
    cout << "\nElement at 4th Index : " << v.at(4) << endl;
    cout << "\nFront " << v.front() << endl;
    cout << "\nBack " << v.back() << endl;
    cout << "\nBefore PopBack" << endl;
    for (auto i = v.begin(); i != v.end(); i++)
    {
        cout << *i << " ";
    }
    cout << endl;
    v.pop_back();
    cout << "\nAfter" << endl;
    for (int i : v)
    {
        cout << i << " ";
    }
    cout << endl;
    vector<int> a(v);
    for (int i : a)
    {
        cout << i << " ";
    }
    cout << endl;
    vector<int> b(5, 4);
    for (int i : b)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}