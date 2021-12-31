#include <bits/stdc++.h>
using namespace std;
int main()
{

    // write your code here
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        int *dp = new int[n + 1];
        dp[0] = 1;
        for (int i = 1; i < n; i++)
        {
            if (a[i] > a[i - 1])
            { // left to right
                dp[i] = dp[i - 1] + 1;
            }
            else
            {
                dp[i] = 1;
            }
        }

        for (int i = n - 2; i >= 0; i--)
        {
            if (a[i] > a[i + 1] && dp[i] <= dp[i + 1])
            { // right to left
                dp[i] = dp[i + 1] + 1;
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
            ans += dp[i];

        cout << ans << endl;
        delete[] dp;
    }
    return 0;
}