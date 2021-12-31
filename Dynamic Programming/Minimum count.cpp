#include <bits/stdc++.h>
using namespace std;
double distanc(int *x, int *y, int i, int j)
{
    double difference_x = x[i] - x[j];
    double difference_y = y[i] - y[j];
    double ans = sqrt((difference_x * difference_x) + (difference_y * difference_y));
    return ans;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n;
        cin >> n;
        int *x = new int[n + 1];
        int *y = new int[n + 1];
        int *f = new int[n + 1];
        for (int i = 1; i <= n; i++)
        {
            cin >> x[i] >> y[i] >> f[i];
        }

        double *dp = new double[n + 1];
        dp[1] = f[1];
        for (int i = 2; i <= n; i++)
        {
            dp[i] = INT_MIN;
            for (int j = 1; j < i; j++)
            {

                dp[i] = max(dp[i], (f[i] + dp[j]) - (distanc(x, y, i, j)));
            }
        }

        cout << fixed;
        cout.precision(6);

        cout << dp[n] << endl;

        delete[] dp;
        delete[] x;
        delete[] y;
        delete[] f;
    }
    // write your code here

    return 0;
}