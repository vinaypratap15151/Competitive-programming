// Given a NxM matrix containing Uppercase English Alphabets only. Your task is to tell if there is a path in the given matrix which makes the sentence “CODINGNINJA” .
// There is a path from any cell to all its neighbouring cells. A neighbour may share an edge or a corner.
    
// Input Format :
// First line will contain T(number of test case), each test case follows as.
// Line 1 : Two space separated integers N  and M, where N is number of rows and M is number of columns in the matrix.
// Next N lines : N rows of the matrix. First line of these N line will contain 0th row of matrix, second line will contain 1st row and so on
// Assume input to be 0-indexed based

// Output Format :
// Print 1 if there is a path which makes the sentence “CODINGNINJA” else print 0, for each test case in a new line

// Constraints :
// 1 <= T <= 10
// 1 <= N <= 1000
// 1 <= M <= 1000
    
// Sample Input :
// 1
// 2 11
// CXDXNXNXNXA
// XOXIXGXIXJX

// Sample Output :
// 1



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
