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
        int ans = n % 4;
        int ans1;
        if (ans == 0)
        {
            ans1 = n;
        }
        else if (ans == 1)
        {
            ans1 = 1;
        }
        else if (ans == 2)
        {
            ans1 = n + 1;
        }
        else
        {
            ans1 = 0;
        }
        cout << ans1 << endl;
    }
    return 0;
}