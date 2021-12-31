#include <bits/stdc++.h>
using namespace std;
int main()
{

    // write your code here
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 1; i <= n; i++)
        {
            a[i] = 0;
        }

        int m;
        cin >> m;
        while (m--)
        {
            int l, r;
            cin >> l >> r;
            a[l] += 1;
            if (r + 1 <= n)
            {
                a[r + 1] -= 1;
            }
        }
        for (int i = 2; i <= n; i++)
        {
            a[i] = a[i] + a[i - 1];
        }

        int coins[n];
        for (int i = 1; i <= n; i++)
        {
            coins[i] = 0;
        }

        for (int i = 1; i <= n; i++)
        {
            coins[a[i]]++;
        }

        int atleast[n];
        atleast[n] = coins[n];
        for (int i = n - 1; i >= 0; i--)
        {
            atleast[i] = coins[i] + atleast[i + 1];
        }

        int q;
        cin >> q;
        while (q--)
        {
            int x;
            cin >> x;
            cout << (atleast[x]) << endl;
        }
    }
    return 0;
}