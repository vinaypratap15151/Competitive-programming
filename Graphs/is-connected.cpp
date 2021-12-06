#include <bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>> &a, int sv, int v, vector<bool> &visited)
{

    queue<int> q;
    q.push(sv);

    visited[sv] = true;
    while (!q.empty())
    {
        int x = q.front();

        q.pop();
        for (int i = 0; i < v; i++)
        {
            if (a[x][i] && !visited[i])
            {
                if (i == x)
                {
                    continue;
                }

                q.push(i);

                visited[i] = true;
            }
        }
    }
}
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int v, e;
        cin >> v >> e;
        vector<vector<int>> a(v, vector<int>(v, 0));
        while (e--)
        {
            int sv, ev;
            cin >> sv >> ev;
            a[sv][ev] = 1;
            a[ev][sv] = 1;
        }
        vector<bool> visited(v, false);
        bfs(a, 0, v, visited);
        int flag = 0;
        for (int i = 0; i < v; i++)
        {
            if (!visited[i])
            {
                cout << "false" << endl;
                flag = 1;
                break;
            }
        }
        if (!flag)
        {
            cout << "true" << endl;
        }
    }
    return 0;
}