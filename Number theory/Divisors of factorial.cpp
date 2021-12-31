#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v(1e6, 0);
    for (int i = 2; i <= 100; i++)
    {
        if (!v[i])
        {
            for (int j = i * i * i; j <= 1e6; j += i * i * i)
            {
                v[j] = -1;
            }
        }
    }
    int k = 0;
    for (int i = 1; i <= 1e6; i++)
    {
        if (!v[i])
        {
            v[i] = k + 1;
            k++;
        }
    }

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        if (v[n] == -1)
        {
            cout << "Not Cube Free" << endl;
        }
        else
            cout << v[n] << endl;
    }

    return 0;
}