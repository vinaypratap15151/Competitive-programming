#include <bits/stdc++.h>
using namespace std;
struct edge
{
    int sv;
    int ev;
    int w;
};
int v, e;
vector<int> parent;
int find(int first)
{
    if (parent[first] == first)
    {
        return first;
    }
    return find(parent[first]);
}

bool sorter(edge a, edge b)
{
    return a.w <= b.w;
}
edge *MST(edge *edges)
{
    int count = 0;
    edge *output = new edge[v - 1];
    for (int i = 0; i < e and count < v - 1; i++)
    {
        int parent1 = find(edges[i].sv);
        int parent2 = find(edges[i].ev);
        if (parent1 != parent2)
        {
            output[count] = edges[i];
            count++;
            parent[parent2] = parent1;
        }
    }

    return output;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        cin >> v >> e;
        edge *edges = new edge[e];
        for (int i = 0; i < e; i++)
        {
            cin >> edges[i].sv >> edges[i].ev >> edges[i].w;
        }
        sort(edges, edges + e, sorter);
        for (int i = 0; i < v; i++)
        {
            parent.push_back(i);
        }
        edge *output = MST(edges);
        int ans = 0;
        for (int i = 0; i < v - 1; i++)
        {
            ans += output[i].w;
        }
        cout << ans << endl;
        parent.clear();
    }

    return 0;
}