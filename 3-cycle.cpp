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