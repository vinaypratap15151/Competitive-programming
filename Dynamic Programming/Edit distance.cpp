#include <bits/stdc++.h>
using namespace std;

int find(int W, int wt[], int val[], int n, int **dp)
{
    int output1 = INT_MIN;
    int output2 = INT_MIN;
    if (W <= 0)
    {
        return 0;
    }

    if (n <= 0)
    {
        return 0;
    }
    if (dp[n][W] != -1)
    {
        return dp[n][W];
    }
    if (W - wt[0] >= 0)
    {
        output1 = val[0] + find(W - wt[0], wt + 1, val + 1, n - 1, dp);
    }
    output2 = find(W, wt + 1, val + 1, n - 1, dp);

    int ans = max(output1, output2);
    dp[n][W] = ans;
    return ans;
}

int main()
{

    int n;
    cin >> n;
    int weight[n];
    for (int i = 0; i < n; i++)
    {
        cin >> weight[i];
    }
    int p[n];
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }
    int W;
    cin >> W;
    int **dp = new int *[n + 1];
    for (int i = 0; i <= n; i++)
    {
        dp[i] = new int[1001];
    }

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= 1001; j++)
        {
            dp[i][j] = -1;
        }
    }

    cout << find(W, weight, p, n, dp);

    return 0;
}