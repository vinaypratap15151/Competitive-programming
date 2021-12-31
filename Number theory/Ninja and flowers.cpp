#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> vv;
    unordered_set<int> s;
    vector<bool> v(n, true);
    v[0] = false;
    v[1] = false;
    for (int i = 2; i * i <= n; i++)
    {
        if (v[i])
        {
            for (int j = i * i; j <= n; j += i)
            {
                v[j] = false;
            }
        }
    }
    for (int i = 0; i <= n; i++)
    {
        if (v[i])
        {
            vv.push_back(i);
        }
    }
    for (int i = 1; i < vv.size(); i++)
    {
        s.insert((vv[i - 1] + vv[i] + 1));
    }
    int count = 0;
    for (int i = 0; i < vv.size(); i++)
    {
        if (s.count(vv[i]))
            count++;
    }
    cout << count;

    return 0;
}