#include <bits/stdc++.h>
using namespace std;
int find(string s1, string s2, int n, int m, int **dp)
{
    if (n == 0)
        return 1000;
    if (m <= 0)
        return 1;
    if (dp[n][m] != -1)
        return dp[n][m];
    int ans1 = find(s1.substr(1), s2, n - 1, m, dp);
    int p = 0;
    int i = 0;
    for (; i < m; i++)
    {
        if (s2[i] == s1[0])
        {
            p = i;
            break;
        }
    }
    if (i == m)
        return 1;
    int ans2 = 1 + find(s1.substr(1), s2.substr(p + 1), n - 1, m - p - 1, dp);
    return dp[n][m] = min(ans1, ans2);
}
int main()
{

    string s1, s2;
    cin >> s1 >> s2;
    int **dp = new int *[s1.size() + 1];
    for (int i = 0; i <= s1.size(); i++)
    {
        dp[i] = new int[s2.size() + 1];
        for (int j = 0; j <= s2.size(); j++)
        {
            dp[i][j] = -1;
        }
    }

    cout << find(s1, s2, s1.size(), s2.size(), dp);

    return 0;
}