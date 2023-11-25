#include <iostream>
using namespace std;
/*
    To solve problem with recursion remember this
    1-> find the base case
    2->solve the one part recursion will handle rest of things
    optional
    1->processing
*/
void reachHome(int src, int dest)
{
    cout << "\nSource is : " << src << " Destination : " << dest << endl;
    // base case
    if (src == dest)
    {
        cout << "\n\t\tSuccessfully Reached Home" << endl;
        return;
    }
    // processing
    src++;
    // recursive call
    reachHome(src, dest);
}
int main()
{
    int src = 1, dest = 10;
    reachHome(src, dest);
    return 0;
}