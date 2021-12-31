

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll phi[1000004], sum[1000004];
ll n = 1000002;
void etf()
{
    for (int i = 1; i <= n; i++)
    {
        phi[i] = i;
    }
    for (int i = 2; i <= n; i++)
    {
        if (phi[i] == i)
        {
            phi[i] = i - 1;
            for (int j = i * 2; j <= n; j += i)
            {
                phi[j] = (phi[j] * (i - 1)) / i;
            }
        }
    }
}
void lcm_sum()
{
    etf();
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j += i)
        {
            sum[j] += (i * phi[i]);
        }
    }
}

int main()
{
    int t;
    cin >> t;
    lcm_sum();
    while (t--)
    {
        ll m;
        cin >> m;
        ll answer = sum[m];
        answer = (answer + 1) * m;
        answer = answer / 2;
        cout << answer << endl;
    }

    return 0;
}