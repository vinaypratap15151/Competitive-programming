#include <bits/stdc++.h>
using namespace std;
bool compare(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}
int main()
{

    // write your code here
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end(), compare);
    int ans = 1;
    int last_time = v[0].second;
    for (int i = 1; i < n; i++)
    {
        if (v[i].first >= last_time)
        {
            last_time = v[i].second;
            ans++;
        }
    }
    cout << ans;
    return 0;
}