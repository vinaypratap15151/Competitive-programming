#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int ans = INT_MIN;
        int i = 0;
        while (i <= 32)
        {
            if ((n & (1 << i)) != 0)
            {
                ans = i;
                break;
            }
            i++;
        }
        if (ans != INT_MIN)
            cout << (n & (1 << ans)) << endl;
        // write your code here
    }
    return 0;
}