#include <bits/stdc++.h>
using namespace std;
bool compare(pair<int, int> p1, pair<int, int> p2)
{
    double f = (double)p1.first / p1.second;
    double s = (double)p2.first / p2.second;
    return f > s;
}
int main()
{
    int n, w;
    cin >> n >> w;

    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end(), compare);
    double ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (w >= v[i].second)
        {
            w -= v[i].second;
            ans += v[i].first;
        }
        else
        {
            double vw = (double)v[i].first / v[i].second;
            ans += vw * w;
            w = 0;
            break;
        }
    }
    cout << fixed << setprecision(6) << ans;

    return 0;
}