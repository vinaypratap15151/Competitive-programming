#include <bits/stdc++.h>
using namespace std;

int flag = 0;
unordered_map<int, int> m;
void print(vector<vector<int>> &edges, int v, vector<bool> &visited, int sv, int ev)
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
            if (i == x)
            {
                continue;
            }
            if (edges[x][i] && !visited[i])
            {
                m[i] = x;
                if (i == ev)
                {
                    flag = 1;
                    return;
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
        vector<vector<int>> edges(v, vector<int>(v, 0));
        for (int i = 0; i < e; i++)
        {
            int sv, ev;
            cin >> sv >> ev;
            edges[sv][ev] = 1;
            edges[ev][sv] = 1;
        }
        int start, end;
        cin >> start >> end;
        vector<bool> visited(v, false);
        print(edges, v, visited, start, end);
        if (flag)
        {
            int ele = end;
            while (ele != start)
            {
                cout << ele << " ";
                ele = m[ele];
            }
            cout << start;
            cout << endl;
        }
        m.clear();
        flag = 0;
    }

    return 0;
}