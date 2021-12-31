
#include <bits/stdc++.h>

#define endl '\n'

#define int long long int
#define MAX 1000001
using namespace std;

unsigned int ets[MAX], G[MAX];

int main()
{
    for (int i = 0; i < MAX; i++)
    {
        ets[i] = i;
    }

    for (int i = 2; i < MAX; i++)
    {
        if (ets[i] == i)
        {
            ets[i] = i - 1;

            for (int j = 2 * i; j < MAX; j += i)
                ets[j] = (ets[j] * (i - 1)) / i;
        }
    }

    for (int i = 2; i < MAX; i++)
    {
        G[i] = ets[i];
        for (long long j = 2; j * i < MAX; j++)
        {
            G[i * j] += j * ets[i];
        }
    }
    G[1] = 0;
    for (int i = 2; i < MAX; i++)
        G[i] += G[i - 1];

    // write your code here
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        cout << G[n] << endl;
    }
    return 0;
}
