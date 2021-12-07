#include <bits/stdc++.h>
using namespace std;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
bool valid(int a, int b, int n, int m)
{
    return (a >= 0 and a < n and b >= 0 and b < m);
}

bool dfs(vector<vector<char>> &v, int i, int j, int k, int x, int y, vector<vector<bool>> &visited, int n, int m, char ch)
{
    if (i == x and j == y and k >= 4)
    {
        return true;
    }
    visited[i][j] = true;
    if (x < 0)
    {
        x = i;
        y = j;
        visited[x][j] = false;
    }

    for (int t = 0; t < 4; t++)
    {
        int xx = i + dx[t];
        int yy = j + dy[t];
        if (valid(xx, yy, n, m) and !visited[xx][yy] and v[xx][yy] == ch and dfs(v, xx, yy, k + 1, x, y, visited, n, m, ch))
        {
            return true;
        }
    }
    visited[i][j] = false;
    return false;
}
int solve(vector<vector<char>> &v, int n, int m)
{
    vector<vector<bool>> visited(n + 1, vector<bool>(m + 1, false));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int x = -1;
            int y = -1;
            if (!visited[i][j] and dfs(v, i, j, 1, x, y, visited, n, m, v[i][j]))
            {
                return 1;
            }
        }
    }
    return 0;
}
int main()
{

    int n, m;
    cin >> n >> m;
    vector<vector<char>> v(n, vector<char>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];
        }
    }
    cout << solve(v, n, m);
    return 0;
}