#include <bits/stdc++.h>
using namespace std;
int main()
{

  int t;
  cin >> t;
  while (t--)
  {
    int v, e;
    cin >> v >> e;
    vector<pair<int, int>> g[v + 1];
    while (e--)
    {
      int sv, ev, w;
      cin >> sv >> ev >> w;
      g[sv].push_back({ev, w});
      g[ev].push_back({sv, w});
    }

    vector<int> weight(v + 1, INT_MAX);
    vector<int> parent(v + 1);
    vector<bool> visited(v + 1, false);
    weight[0] = 0;
    parent[0] = -1;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});
    while (!pq.empty())
    {
      int ele = pq.top().second;

      pq.pop();
      visited[ele] = true;
      for (auto it : g[ele])
      {
        int vert = it.first;
        int distan = it.second;
        if (!visited[vert] and weight[vert] > distan)
        {
          weight[vert] = distan;
          parent[vert] = ele;
          pq.push({weight[vert], vert});
        }
      }
    }
    int sum = 0;
    for (int i = 1; i < v; i++)
    {
      sum += weight[i];
    }
    cout << sum;
    cout << endl;
  }
  return 0;
}