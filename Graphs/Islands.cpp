// An island is a small piece of land surrounded by water . A group of islands is said to be connected if we can reach from any given island to any other 
// island in the same group . Given N islands (numbered from 0 to N - 1) and M pair of integers (u and v) denoting island, u is connected to island v and vice versa.
//  Can you count the number of connected groups of islands?

// Input Format:
// The first line of input will contain T(number of test cases), each test case follows as.
// Line 1: Two Integers N and M (separated by space)
// Next 'M' lines, each have two space-separated integers, 'u' and 'v', denoting that there exists an edge between Vertex 'u' and Vertex 'v'.

// Output Format:
// Print number of Islands for each test case in new line.

// Constraints:
// 1 <= T <= 10
// 1 <= N <= 1000
// 1 <= M <= min((N*(N-1))/2, 1000)
// 0 <= u[i] ,v[i] < N

// Output Return Format :
// The count the number of connected groups of islands
// Sample Input :
// 1
// 2 1
// 0 1
// Sample Output :
// 1 


//Solution:

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
