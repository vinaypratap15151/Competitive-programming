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
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        int k;
        cin >> k;

        bool **dp = new bool *[n + 1];
        for (int i = 0; i <= n; i++)
        {
            dp[i] = new bool[k + 1];
        }
        for (int i = 0; i <= n; i++)
        {
            dp[i][0] = true;
        }
        for (int i = 0; i <= k; i++)
        {
            dp[0][i] = false;
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= k; j++)
            {
                dp[i][j] = dp[i - 1][j];
                if (j >= a[n - i])
                {
                    dp[i][j] = dp[i - 1][j - a[n - i]] || dp[i - 1][j];
                }
            }
        }
        if (dp[n][k] == false)
        {
            cout << "No" << endl;
        }
        else
            cout << "Yes" << endl;

        for (int i = 0; i <= n; i++)
        {
            delete dp[i];
        }
        delete[] dp;
    }
    return 0;
}