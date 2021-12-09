// Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
// Find and print the total weight of Minimum Spanning Tree (MST) using Kruskal's algorithm.
    
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
