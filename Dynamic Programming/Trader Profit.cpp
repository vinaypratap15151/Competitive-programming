#include <bits/stdc++.h>
using namespace std;
int find(int cap[], int ass[], int n, int x, int **dp)
{
    if (n == 0)
    {
        return 0;
    }

    if (dp[n][x] != -1)
    {
        return dp[n][x];
    }
    int output1 = INT_MAX;
    int output2 = INT_MAX;
    int output3 = INT_MAX;
    if (x == 0)
    {
        output1 = find(cap + 1, ass + 1, n - 1, x + 1, dp) + ass[0];
    }
    else if (x == n)
    {
        output1 = find(cap + 1, ass + 1, n - 1, x - 1, dp) + cap[0];
    }
    else
    {
        output2 = find(cap + 1, ass + 1, n - 1, x + 1, dp) + ass[0];
        output3 = find(cap + 1, ass + 1, n - 1, x - 1, dp) + cap[0];
    }

    dp[n][x] = min(output1, min(output2, output3));
    return dp[n][x];
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int cap[n], ass[n];
        for (int i = 0; i < n; i++)
        {
            cin >> cap[i] >> ass[i];
        }

        int **dp = new int *[n + 1];
        for (int i = 0; i <= n; i++)
        {
            dp[i] = new int[n + 1];
            for (int j = 0; j <= n; j++)
            {
                dp[i][j] = -1;
            }
        }

        cout << find(cap, ass, n, 0, dp) << endl;
    }

    return 0;
}