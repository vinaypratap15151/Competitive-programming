// Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
// Find and print the total weight of Minimum Spanning Tree (MST) using Prim's algorithm.  
  
// Input Format :
// First line will contain T(number of test case), each test case follows as. 
// Line 1: Two Integers V and E (separated by space)
// Next E lines : Three integers ei, ej and wi, denoting that there exists an edge between vertex ei and vertex ej with weight wi (separated by space)
  
// Output Format :
// Weight of MST for each test case in new line.
  
// Constraints :
// 1 <= T <= 10
// 2 <= V, E <= 10^5
// 1 <= wt <= 10^4

// Sample Input 1 :
// 1
// 4 4
// 0 1 3
// 0 3 5
// 1 2 1
// 2 3 8
  
// Sample Output 1 :
// 9

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
