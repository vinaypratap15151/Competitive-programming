#include <bits/stdc++.h>
using namespace std;

bool check_path(vector<vector<int>> &edges, int v, int sv, int ev, vector<bool> &visited)
{
    if (sv == ev)
    {
        return true;
    }
    visited[sv] = true;
    for (int i = 0; i < v; i++)
    {
        if (edges[sv][i] && !visited[i])
        {
            bool ans = check_path(edges, v, i, ev, visited);
            if (ans)
                return true;
        }
    }
    return false;
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
        int v1, v2;
        cin >> v1 >> v2;
        vector<bool> visited(v, false);

        if (check_path(edges, v, v1, v2, visited))
        {
            cout << "true" << endl;
        }
        else
        {
            cout << "false" << endl;
        }
    }
    return 0;
}
