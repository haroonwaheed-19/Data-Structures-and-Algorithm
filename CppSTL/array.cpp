#include <iostream>
#include <array>
using namespace std;
int main()
{
    array<int, 5> a = {1, 2, 3, 4, 5};
    int size = a.size();
    cout << "\nsize is : " << size << endl;
    cout << "\nElement at 3rd Index:" << a.at(3) << endl;
    if (a.empty())
    {
        cout << "\nEmpty" << endl;
    }
    else
    {
        cout << "\nNot Empty" << endl;
    }

    cout << "\nFirst element " << a.front() << endl;
    cout << "\nLast element " << a.back() << endl;
    return 0;
}