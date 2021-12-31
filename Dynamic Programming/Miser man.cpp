#include <bits/stdc++.h>
using namespace std;
int find(int n, int k, int *a, int ***dp, int ongoing)
{
    if (n == 0 || k == 0)
    {
        return 0;
    }
    if (dp[n][k][ongoing] >= 0)
    {
        return dp[n][k][ongoing];
    }

    int output1 = find(n - 1, k, a + 1, dp, ongoing);
    int output2;
    if (ongoing == 1)
    {
        output2 = find(n - 1, k - 1, a + 1, dp, 0) + a[0];
    }
    else
    {

        if (k > 0)
        {
            output2 = find(n - 1, k, a + 1, dp, 1) - a[0];
        }
    }

    dp[n][k][ongoing] = max(output1, output2);
    return dp[n][k][ongoing];
}

int main()
{

    int t;
    cin >> t;
    while (t--)
    {

        int k, n;
        cin >> k >> n;
        int *a = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        int ***dp = new int **[n + 1];
        for (int i = 0; i <= n; i++)
        {
            dp[i] = new int *[k + 1];
            for (int j = 0; j <= k; j++)
            {
                dp[i][j] = new int[2];
                for (int p = 0; p < 2; p++)
                {
                    dp[i][j][p] = -1;
                }
            }
        }

        cout << find(n, k, a, dp, 0) << endl;
    }
    return 0;
}