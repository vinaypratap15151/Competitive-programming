// Bellman-Ford Algorithm
// you are given a weighted directed graph G with n vertices and m edges, and two specified vertex src and des.
// You want to find the length of shortest paths from vertex src to des.
// The graph may contain the edges with negative weight.

// Input Format:
// First line of input will contain T(number of test case), each test case follows as.
// Line1: contain two space-separated integers N and M denoting the number of vertex and number of edges
// in graph respectively.
// Line2: contain two space-separated integers src, des.
// Next M line will contain three space-separated integers a, b, wt representing the edge from a to b with weight wt.

// Output Format:
// For each test case print the distance of des from src in new line.
// Note: In case of no path is found print (10 ^ 9) in that case.

// Constraints:
// 1 <= T <= 100
// 1 <= N <= 200
// 1 <= M <= min(800, N*(N-1))
// 1 <= a,b <= N
// -10^5 <= wt <= 10^5

// Sample Input:
// 1
// 3 6
// 3 1
// 3 1 -2
// 1 3 244
// 2 3 -2
// 2 1 201
// 3 2 220
// 1 2 223
// Sample output:
// -2

#include <bits/stdc++.h>
using namespace std;
struct edge
{
  int sv;
  int ev;
  int w;
};
void find(edge *edges, int v, int e, int src, int dest)
{
  vector<int> dist(v + 1, 1e9);
  dist[src] = 0;
  for (int i = 0; i < v - 1; i++)
  {
    for (int j = 0; j < e; j++)
    {
      if (dist[edges[j].sv] < 1e9)
      {
        dist[edges[j].ev] = min(dist[edges[j].ev], dist[edges[j].sv] + edges[j].w);
      }
    }
  }

  cout << dist[dest] << endl;
}
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int v, e;
    cin >> v >> e;
    int src, dest;
    cin >> src >> dest;

    edge *edges = new edge[e];
    for (int i = 0; i < e; i++)
    {
      cin >> edges[i].sv >> edges[i].ev >> edges[i].w;
    }

    find(edges, v, e, src, dest);
  }

  return 0;
}