// 3 Cycle
// Send Feedback
// Given a graph with N vertices (numbered from 1 to N) and Two Lists (U,V) of size M where (U[i],V[i]) and (V[i],U[i]) are connected by an edge ,
// then count the distinct 3-cycles in the graph. A 3-cycle PQR is a cycle in which (P,Q), (Q,R) and (R,P) are connected an edge.
  
// Input Format :
// Line 1 : Two integers N and M
// Line 2 : List u of size of M
// Line 3 : List v of size of M

// Return Format :
// The count the number of 3-cycles in the given Graph

// Constraints :
// 1<=N<=100
// 1<=M<=(N*(N-1))/2
// 1<=u[i],v[i]<=N

// Sample Input:
// 3 3
// 1 2 3
// 2 3 1
  
// Sample Output:
// 1





#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> v1, v2;
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        v1.push_back(x);
    }
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        v2.push_back(x);
    }

    vector<vector<int>> v(n, vector<int>(n, 0));
    for (int i = 0; i < m; i++)
    {

        v[v1[i] - 1][v2[i] - 1] = 1;
        v[v2[i] - 1][v1[i] - 1] = 1;
    }

    int count = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (v[i][j] == 1 && i != j)
            {
                for (int k = 0; k < n; k++)
                {
                    if (v[j][k] == 1 && j != k && i != k)
                    {
                        if (v[i][k] == 1)
                        {
                            count++;
                        }
                    }
                }
            }
        }
    }

    cout << (count) / 6;

    return 0;
}
