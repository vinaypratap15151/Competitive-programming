#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll m = 1e9 + 7;

ll dp[101][101][2];

ll find(int n, int k, int first)
{
    if (n == 1)
    {
        if (k == 0)
            return 1;
        return 0;
    }
    if (k < 0)
        return 0;

    if (dp[n][k][first] != -1)
        return dp[n][k][first];
    if (first == 0)
    {
        int ans = (find(n - 1, k, 1) % m + find(n - 1, k, 0) % m) % m;
        return dp[n][k][first] = ans;
    }
    else
    {
        int ans = (find(n - 1, k, 0) % m + find(n - 1, k - 1, 1) % m) % m;
        return dp[n][k][first] = ans;
    }
}
int main()
{

    for (int i = 0; i <= 101; i++)
    {
        for (int j = 0; j <= 101; j++)
        {
            dp[i][j][0] = -1;
            dp[i][j][1] = -1;
        }
    }

    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        cout << (find(n, k, 0) % m + find(n, k, 1) % m) % m << endl;
    }
    return 0;
}