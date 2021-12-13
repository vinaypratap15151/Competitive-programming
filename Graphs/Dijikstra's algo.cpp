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

    vector<int> dist(v + 1, INT_MAX);
    dist[0] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});
    while (!pq.empty())
    {
      int ele = pq.top().second;
      int distance = pq.top().first;
      pq.pop();
      for (auto it : g[ele])
      {
        int vert = it.first;
        int distan = it.second;
        if (dist[vert] > distance + distan)
        {
          dist[vert] = distance + distan;
          pq.push({dist[vert], vert});
        }
      }
    }

    for (int i = 0; i < v; i++)
    {
      cout << i << " " << dist[i] << endl;
    }
    cout << endl;
  }
  return 0;
}