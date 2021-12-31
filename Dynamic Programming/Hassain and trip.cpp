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
        long long m = 1e9 + 7;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        long long **dp = new long long *[n];
        for (int i = 0; i < n; i++)
        {
            dp[i] = new long long[101];
        }

        for (int i = 0; i < n; i++)
        {
            for (int g = 0; g <= 100; g++)
            {
                dp[i][g] = 0;
            }
        }

        dp[0][a[0]] = 1;
        long long sum = dp[0][1];
        for (int i = 1; i < n; i++)
        {
            for (int k = 0; k < i; k++)
            {

                if (a[i] > a[k])
                {
                    for (int g = 1; g <= 100; g++)
                    {
                        int new_gcd = __gcd(g, a[i]);
                        dp[i][new_gcd] = (dp[i][new_gcd] + dp[k][g]) % m;
                    }
                }
            }

            dp[i][a[i]]++;
            sum = (sum + dp[i][1]) % m;
        }

        cout << sum << endl;
        for (int i = 0; i < n; i++)
        {
            delete[] dp[i];
        }
        delete[] dp;
    }
    return 0;
}