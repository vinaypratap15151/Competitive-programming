#include <bits/stdc++.h>
using namespace std;
void print(vector<vector<int>> &edges, int v, vector<bool> &visited, int sv)
{
  queue<int> q;
  q.push(sv);
  visited[sv] = true;
  while (!q.empty())
  {
    int x = q.front();

    cout << x << " ";
    q.pop();

    for (int i = 0; i < v; i++)
    {
      if (i == x)
      {
        continue;
      }
      if (edges[x][i] && !visited[i])
      {

        q.push(i);
        visited[i] = true;
      }
    }
  }
}
int main()
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
  vector<bool> visited(v, false);
  print(edges, v, visited, 0);
  for (int i = 0; i < v; i++)
  {
    if (!visited[i])
    {
      print(edges, v, visited, i);
    }
  }
  return 0;
}