// Dijkstra's Algorithm

// Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
// Find and print the shortest distance from the source vertex (i.e. Vertex 0) to all other vertices (including source vertex also) using Dijkstra's Algorithm.
// Print the ith vertex number and the distance from source in one line separated by space. Print different vertices in different lines.
  
// Note : Order of vertices in output doesn't matter.
  
// Input Format :
// First line will contain T(number of test case), each test case follows as.
// Line 1: Two Integers V and E (separated by space)
// Next E lines : Three integers ei, ej and wi, denoting that there exists an edge between vertex ei and vertex ej with weight wi (separated by space)
  
// Output Format :
// In different lines, ith vertex number and its distance from source (separated by space)
  
// Constraints :
// 1 <= T <= 10
// 2 <= V, E <= 10^3

// Sample Input 1 :
// 1
// 4 4
// 0 1 3
// 0 3 5
// 1 2 1
// 2 3 8
  
// Sample Output 1 :
// 0 0
// 1 3
// 2 4
// 3 5




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
