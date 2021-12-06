#include <bits/stdc++.h>
using namespace std;

vector<int> get_path(vector<vector<int>> &edges, int v, int sv, int ev, vector<bool> &visited)
{
    if (sv == ev)
    {
        vector<int> ans1;
        ans1.push_back(sv);
        return ans1;
    }
    visited[sv] = true;

    for (int i = 0; i < v; i++)
    {
        if (edges[sv][i] && !visited[i])
        {
            vector<int> ans2 = get_path(edges, v, i, ev, visited);
            if (ans2.size() != 0)
            {
                ans2.push_back(sv);
                return ans2;
            }
        }
    }
    vector<int> ans3;
    return ans3;
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
        vector<int> ans = get_path(edges, v, v1, v2, visited);
        if (ans.size())
        {
            for (int i = 0; i < ans.size(); i++)
            {
                cout << ans[i] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}