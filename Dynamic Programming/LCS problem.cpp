#include <bits/stdc++.h>
using namespace std;
int find(char *s1, char *s2, int m, int n, int **dp)
{

    if (m == 0 && n == 0)
        return 0;
    if (m == 0)
        return n;
    if (n == 0)
        return m;

    if (dp[m][n] != -1)
    {
        return dp[m][n];
    }

    if (s1[0] == s2[0])
    {
        int ans1 = find(s1 + 1, s2 + 1, m - 1, n - 1, dp);
        dp[m][n] = ans1;
        return ans1;
    }

    else
    {

        int ans2 = 1 + find(s1 + 1, s2 + 1, m - 1, n - 1, dp);
        int ans3 = 1 + find(s1 + 1, s2, m - 1, n, dp);
        int ans4 = 1 + find(s1, s2 + 1, m, n - 1, dp);
        int anss = min(ans2, min(ans3, ans4));

        dp[m][n] = anss;
        return anss;
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        char s1[100];
        char s2[100];
        cin >> s1 >> s2;
        int m = strlen(s1);
        int n = strlen(s2);
        int **dp = new int *[m + 1];
        for (int i = 0; i <= m; i++)
        {
            dp[i] = new int[n + 1];
        }

        for (int i = 0; i <= m; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                dp[i][j] = -1;
            }
        }
        cout << find(s1, s2, m, n, dp) << endl;
    }

    return 0;
}