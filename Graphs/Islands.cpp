#include <bits/stdc++.h>
using namespace std;
void find_groups(vector<vector<int>> &connected, int n, int si, vector<bool> &visited)
{
    visited[si] = true;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i] and connected[si][i])
        {
            find_groups(connected, n, i, visited);
        }
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int islands, connected_islands;
        cin >> islands >> connected_islands;
        vector<vector<int>> connected(islands, vector<int>(islands, 0));
        while (connected_islands--)
        {
            int si, ei;
            cin >> si >> ei;
            connected[si][ei] = 1;
            connected[ei][si] = 1;
        }

        vector<bool> visited(islands, false);
        find_groups(connected, islands, 0, visited);
        int count = 1;
        for (int i = 0; i < islands; i++)
        {
            if (!visited[i])
            {
                count++;
                find_groups(connected, islands, i, visited);
            }
        }
        cout << count << endl;
    }
    return 0;
}