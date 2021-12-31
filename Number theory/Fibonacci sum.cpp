#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int power(int a, int n, int m)
{
    if (a == 0)
        return 0;
    if (n == 0)
        return 1;

    if (n % 2 == 0)
    {
        ll ans = power(a, n / 2, m) % m;
        ans = (ans * ans) % m;
        return ans % m;
    }
    else
    {
        ll ans = power(a, n - 1, m) % m;
        ans = ((ans) * (a)) % m;
        return ans % m;
    }
}

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n, p;
        cin >> n >> p;
        if (n >= p)
        {
            cout << "0" << endl;
        }
        else
        {
            ll val = -1;
            for (int i = n + 1; i < p; i++)
            {
                val = (val * (power(i, p - 2, p) % p)) % p;
            }

            ll ans = (val) % p + p;
            cout << ans << endl;
        }
    }

    return 0;
}