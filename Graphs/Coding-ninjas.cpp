#include <bits/stdc++.h>
using namespace std;
int dx[] = {1, 0, -1, 0, 1, -1, 1, -1};
int dy[] = {0, -1, 0, 1, 1, 1, -1, -1};
bool valid(int x, int y, int n, int m)
{
    return (x >= 0 and x < n and y >= 0 and y < m);
}
bool dfs(vector<vector<char>> &g, int n, int m, int idx, int i, int j, vector<vector<bool>> &visited, string s)
{

    if (idx == s.size())
    {
        return true;
    }
    if (visited[i][j])
    {
        return false;
    }
    visited[i][j] = true;

    for (int k = 0; k < 8; k++)
    {
        int x = i + dx[k];
        int y = j + dy[k];

        if (s[idx] == g[x][y] and valid(x, y, n, m) and dfs(g, n, m, idx + 1, x, y, visited, s))
        {
            return true;
        }
    }

    return false;
}
int solve(vector<vector<char>> &g, int n, int m)
{
    vector<vector<bool>> visited(n + 1, vector<bool>(m + 1, false));
    string s = "CODINGNINJA";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (g[i][j] == 'C' && !visited[i][j])
            {
                if (dfs(g, n, m, 1, i, j, visited, s))
                    return 1;
            }
        }
    }
    return 0;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> g(n + 1, vector<char>(m + 1));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> g[i][j];
            }
        }

        cout << solve(g, n + 1, m + 1) << endl;
        ;
    }

    return 0;
}