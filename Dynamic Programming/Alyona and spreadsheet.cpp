#include <bits/stdc++.h>
using namespace std;
int main()
{

    // write your code here
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int a[n + 1][m + 1];
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cin >> a[i][j];
            }
        }

        int dp[n + 1][m + 1];
        for (int i = 1; i <= m; i++)
        {
            dp[1][i] = 1;
        }

        for (int i = 2; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (a[i][j] >= a[i - 1][j])
                {
                    dp[i][j] = dp[i - 1][j];
                }
                else
                {
                    dp[i][j] = i;
                }
            }
        }

        int dp1[n + 1];
        for (int i = 1; i <= n; i++)
        {
            dp1[i] = INT_MAX;
            for (int j = 1; j <= m; j++)
            {
                dp1[i] = min(dp1[i], dp[i][j]);
            }
        }

        int q;
        cin >> q;
        while (q--)
        {

            int l, r;
            cin >> l >> r;

            if (dp1[r] <= l)
            {
                cout << "Yes" << endl;
            }

            else
            {
                cout << "No" << endl;
            }
        }
    }
    return 0;
}