#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int ans = 0;
    vector<int> v(n, 0);
    for (int i = 2; i <= n; i++)
    {
        if (!v[i])
        {
            for (int j = 2 * i; j <= n; j += i)
            {
                v[j]++;
            }
        }
    }
    for (int i = 0; i <= n; i++)
    {
        if (v[i] == 2)
            ans++;
    }
    cout << ans;

    return 0;
}