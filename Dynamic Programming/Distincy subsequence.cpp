#include <bits/stdc++.h>
using namespace std;
int find(string s1, string s2, int n, int m, int **dp)
{

    if (n == 0)
        return m;
    if (m == 0)
        return n;
    if (n == 0 && m == 0)
        return 0;
    if (dp[n][m] != -1)
        return dp[n][m];
    int ans1 = 0;
    if (s1[0] == s2[0])
    {
        ans1 = 1 + find(s1.substr(1), s2.substr(1), n - 1, m - 1, dp);
    }
    else
    {
        ans1 = min(find(s1.substr(1), s2, n - 1, m, dp), find(s1, s2.substr(1), n, m - 1, dp)) + 1;
    }

    return dp[n][m] = ans1;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
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

        cout << find(s1, s2, s1.size(), s2.size(), dp) << endl;
    }

    return 0;
}