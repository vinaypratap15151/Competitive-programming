#include <bits/stdc++.h>
using namespace std;
void print(vector<vector<int>> &edges, int v, int sv, vector<bool> &visited, vector<int> &ans)
{
    visited[sv] = true;
    ans.push_back(sv);
    for (int i = 0; i < v; i++)
    {
        if (edges[sv][i] && !visited[i])
        {
            print(edges, v, i, visited, ans);
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
            edges[sv - 1][ev - 1] = 1;
            edges[ev - 1][sv - 1] = 1;
        }
        vector<bool> visited(v, false);

        for (int i = 0; i < v; i++)
        {
            if (!visited[i])
            {
                vector<int> ans;
                print(edges, v, i, visited, ans);
                sort(ans.begin(), ans.end());
                for (int j = 0; j < ans.size(); j++)
                {
                    cout << ans[j] + 1 << " ";
                }
                cout << endl;
            }
        }
    }
    return 0;
}