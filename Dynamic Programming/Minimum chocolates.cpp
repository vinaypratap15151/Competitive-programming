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
        int dp[n + 1];
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            dp[i] = INT_MAX;
            for (int j = 1; i - j * j >= 0; j++)
            {
                dp[i] = min(dp[i], 1 + dp[i - j * j]);
            }
        }

        cout << dp[n] << endl;
    }
    return 0;
}