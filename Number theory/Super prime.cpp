#include <bits/stdc++.h>
using namespace std;

long long N = 1e6 + 5;
int main()
{
    int n;
    cin >> n;
    vector<int> v(N, 0);
    for (int i = 2; i * i <= N; i++)
    {
        if (!v[i])
        {
            for (int j = i * i; j < N; j += i)
            {
                v[j] = 1;
            }
        }
    }
    int count1 = 0, count2 = 0;
    for (int i = 2; i <= n + 1; i++)
    {
        if (!v[i])
            count1++;
        else
            count2++;
    }
    if (n <= 1)
        cout << "1";
    else
        cout << "2" << endl;
    cout << min(count1, count2) << " " << max(count1, count2);
    return 0;
}