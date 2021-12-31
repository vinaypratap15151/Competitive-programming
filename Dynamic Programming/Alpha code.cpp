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
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        vector<int> inc(n, 1);
        vector<int> dec(n, 1);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {

                if (a[i] > a[j])
                    inc[i] = max(inc[i], inc[j] + 1);
            }
        }

        int ans = 0;
        for (int j = n - 1; j >= 0; j--)
        {
            for (int i = n - 1; i > j; i--)
            {
                if (a[j] > a[i])
                {
                    dec[j] = max(dec[j], dec[i] + 1);
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            ans = max(ans, (inc[i] + dec[i]) - 1);
        }

        cout << ans << endl;
    }

    return 0;
}