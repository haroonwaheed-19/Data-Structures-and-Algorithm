#include <iostream>
using namespace std;

long long int calculateDistinctWay(long long int stairs)
{
    // Base Case
    if (stairs < 0) // when no of stairs less then 0 then 0 way to climb
    {
        return 0;
    }
    if (stairs == 0) // when only one stairs then there is one way to climb
    {
        return 1;
    }

    // recurisve call
    int ans = calculateDistinctWay(stairs - 1) + calculateDistinctWay(stairs - 2); // either you can climb the last stiars by 1 jump or by 2
    return ans;
}
int main()
{
    long long int stairs = 5;
    long long int ans = calculateDistinctWay(stairs);
    cout << "Number of distinct ways to climb " << stairs << " stairs is : " << ans << endl;
    return 0;
}