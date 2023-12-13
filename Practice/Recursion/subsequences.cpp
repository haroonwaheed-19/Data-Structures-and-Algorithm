#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solve(string str, string output, int index, vector<string> &ans)
{
    // base case
    if (index >= str.length())
    {
        if (output.length() > 0)
        {
            ans.push_back(output);
        }
        return;
    }
    // exclude case
    solve(str, output, index + 1, ans);
    // include case
    output.push_back(str[index]);
    solve(str, output, index + 1, ans);
}

int main()
{
    string str = "abc"; // Provide a non-empty input string
    vector<string> ans;
    string output = "";
    int index = 0;
    solve(str, output, index, ans);

    // Print the resulting combinations
    for (const auto &combination : ans)
    {
        cout << combination << " ";
    }
    cout << endl;

    return 0;
}
