#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n, m;
        cin >> n >> m;
        int a[n][m];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> a[i][j];
            }
        }

        int dp[n + 1][m + 1];
        for (int i = 0; i < m; i++)
        {
            dp[0][i] = a[0][i];
        }
        for (int i = 1; i < n; i++)
        {

            for (int j = 0; j < m; j++)
            {
                int ans1 = INT_MAX;
                int ans2 = INT_MAX;
                int ans3 = INT_MAX;
                if (j - 1 >= 0)
                {
                    ans1 = a[i][j] + dp[i - 1][j - 1];
                }
                ans2 = dp[i - 1][j] + a[i][j];
                if (j + 1 < m)
                {
                    ans3 = a[i][j] + dp[i - 1][j + 1];
                }
                dp[i][j] = min(ans1, min(ans2, ans3));
            }
        }
        int anss = INT_MAX;
        for (int i = 0; i < m; i++)
        {
            anss = min(anss, dp[n - 1][i]);
        }
        cout << anss << endl;
    }

    return 0;
}