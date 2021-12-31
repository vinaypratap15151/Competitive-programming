#include <bits/stdc++.h>
using namespace std;
int find(string s1, string s2, int n, int m, int k, int ***dp)
{
    if (k == 0)
        return 0;

    if (k > n || k > m)
        return -1e18;
    if (dp[n][m][k] != -1)
        return dp[n][m][k];
    if (s1[0] != s2[0])
    {

        int ans1 = find(s1.substr(1), s2, n - 1, m, k, dp);
        int ans2 = find(s1, s2.substr(1), n, m - 1, k, dp);

        return dp[n][m][k] = max(ans1, ans2);
    }

    else
    {

        int ans1 = s1[0] + find(s1.substr(1), s2.substr(1), n - 1, m - 1, k - 1, dp);
        int ans2 = find(s1.substr(1), s2, n - 1, m, k, dp);
        int ans3 = find(s1, s2.substr(1), n, m - 1, k, dp);
        return dp[n][m][k] = max(ans1, max(ans2, ans3));
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        string s1, s2;
        cin >> s1 >> s2;
        int k;
        cin >> k;
        int n = s1.size();
        int m = s2.size();
        int ***dp = new int **[n + 1];
        for (int i = 0; i <= n; i++)
        {
            dp[i] = new int *[m + 1];
            for (int j = 0; j <= m; j++)
            {
                dp[i][j] = new int[k + 1];
                for (int p = 0; p <= k; p++)
                {
                    dp[i][j][p] = -1;
                }
            }
        }

        cout << max(0, find(s1, s2, n, m, k, dp)) << endl;
    }

    return 0;
}
