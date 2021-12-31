#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{

    int t;
    cin >> t;
    while (t--)
    {

        int n, w;
        cin >> n >> w;

        vector<pair<ll, ll>> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i].first;
        }

        for (int i = 0; i < n; i++)
        {
            cin >> v[i].second;
        }
        sort(v.begin(), v.end());
        ll ***dp = new ll **[2];
        for (int i = 0; i < 2; i++)
        {
            dp[i] = new ll *[n + 1];

            for (int j = 0; j <= n; j++)
            {
                dp[i][j] = new ll[w + 1];

                for (int k = 0; k <= w; k++)
                {
                    dp[i][j][k] = 0;
                }
            }
        }

        int primes[11] = {1, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= w; j++)
            {
                dp[0][i][j] = dp[0][i - 1][j];
                if (j - v[i - 1].second >= 0)
                {
                    dp[0][i][j] = max(dp[0][i][j], dp[0][i - 1][j - v[i - 1].second] + v[i - 1].first);
                }
            }
        }

        int p = 1;
        for (int prime = 1; prime <= 10; prime++)
        {

            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= w; j++)
                {
                    dp[p][i][j] = dp[p][i - 1][j];
                    if (j - v[i - 1].second >= 0)
                    {
                        dp[p][i][j] = max(dp[p][i][j], max(dp[p][i - 1][j - v[i - 1].second] + v[i - 1].first, dp[p ^ 1][i - 1][j - v[i - 1].second] + v[i - 1].first * primes[prime]));
                    }
                }
            }
            p = p ^ 1;
        }

        cout << dp[0][n][w] << endl;
    }

    return 0;
}