#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string str, int i, int j)
{
    // base case
    if (i > j)
    {
        return false;
    }

    if (str[i] != str[j])
    {
        return false;
    }
    else
    {
        // recursive call
        isPalindrome(str, i + 1, j - 1);
    }
}
int main()
{
    string name = "abbccbba";
    bool check = isPalindrome(name, 0, name.length() - 1);
    if (check)
    {
        cout << "\n\tString is a Palindrome" << endl;
        cout << "\t\t" << name << endl;
    }
    else
    {
        cout << "\n\tString is not a Palindrome" << endl;
        cout << "\t\t" << name << endl;
    }
    return 0;
}