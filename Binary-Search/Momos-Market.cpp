#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, q, x;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    for (int i = 1; i < n; i++)
    {
        v[i] += v[i - 1];
    }
    cin >> q;
    while (q--)
    {
        int x;
        cin >> x;

        int momos = 0;
        int money = 0;
        auto it = lower_bound(v.begin(), v.end(), x);
        if (it != v.end())
        {
            int idx = it - v.begin();
            if (v[idx] > x)
            {
                momos = idx;
                money = v[idx - 1];
            }
            else
            {
                momos = idx + 1;
                money = v[idx];
            }
        }

        cout << momos << " " << (x - money) << endl;
    }

    return 0;
}