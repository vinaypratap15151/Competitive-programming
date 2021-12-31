#include <bits/stdc++.h>
using namespace std;
int m = 1e9 + 7;
int find(int n, int d[], int v, int **dp)
{

    if (v == 0)
    {
        return 1;
    }
    if (n == 0)
    {
        return 0;
    }

    if (v < 0)
    {
        return 0;
    }

    if (dp[v][n] != -1)
    {
        return dp[v][n];
    }

    int output1 = find(n, d, v - d[0], dp);
    int output2 = find(n - 1, d + 1, v, dp);
    dp[v][n] = (output1 + output2) % m;
    return dp[v][n];
}

int main()
{

    // write your code here
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int d[n];
        for (int i = 0; i < n; i++)
        {
            cin >> d[i];
        }

        int v;
        cin >> v;
        int **nums = new int *[v + 1];
        for (int i = 0; i < v + 1; i++)
        {
            nums[i] = new int[n + 1];
        }

        for (int i = 0; i < v + 1; i++)
        {
            for (int j = 0; j < n + 1; j++)
            {
                nums[i][j] = -1;
            }
        }

        cout << (find(n, d, v, nums)) % m << endl;
    }
    return 0;
}