#include <bits/stdc++.h>
using namespace std;
bool check(int mid, vector<long long> v, int n, int k)
{
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += (v[i] / mid);
    }
    if (ans >= k)
    {
        return true;
    }
    return false;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, k;
        cin >> n >> k;
        vector<long long> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }

        sort(v.begin(), v.end());
        int anss = 0;
        int s = 0;
        int e = v[n - 1];
        while (s <= e)
        {
            int mid = (s + e) / 2;
            if (check(mid, v, n, k))
            {
                anss = mid;
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
        }
        cout << anss << endl;
    }
    return 0;
}