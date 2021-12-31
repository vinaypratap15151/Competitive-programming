
#include <bits/stdc++.h>
using namespace std;

int phie(int n)
{
    int result = n; // n*phie(1-1/p)*(1-1/2p)..
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            while (n % i == 0)
            {
                n /= i;
            }

            result -= result / i;
            // n(1-1/p)=n-n/p
        }
    }
    if (n > 1)
    { // if n is less then 4 that is 2*2<=3 for that edge case
        result -= result / n;
    }
    return result;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << phie(n) << endl;
    }
}
