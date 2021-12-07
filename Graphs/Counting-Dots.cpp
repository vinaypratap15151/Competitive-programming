// Gary has a board of size NxM. Each cell in the board is a coloured dot. There exist only 26 colours denoted by uppercase Latin characters (i.e. A,B,...,Z).
//  Now Gary is getting bore and wants to play a game. The key of this game is to find a cycle that contain dots of same colour. Formally,
// we call a sequence of dots d1, d2, ..., dk a cycle if and only if it meets the following condition:

// 1. These k dots are different: if i ≠ j then di is different from dj.
// 2. k is at least 4.
// 3. All dots belong to the same colour.
// 4. For all 1 ≤ i ≤ k - 1: di and di + 1 are adjacent. Also, dk and d1 should also be adjacent. Cells x and y are called adjacent if they share an edge.
// Since Gary is colour blind, he wants your help. Your task is to determine if there exists a cycle on the board.
// Assume input to be 0-indexed based.
    
// Input Format :
// Line 1 : Two integers N and M, the number of rows and columns of the board
// Next N lines : a string consisting of M characters, expressing colors of dots in each line. Each character is an uppercase Latin letter.
    
// Output Format :
// Return 1 if there is a cycle else return 0
    
// Constraints :
// 2 ≤ N, M ≤ 400

// Sample Input :
// 3 4
// AAAA
// ABCA
// AAAA
// Sample Output :
// 1






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
        visited[x][y] = false;
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
