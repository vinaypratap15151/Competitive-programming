#include <bits/stdc++.h>
using namespace std;
void find(int a[], int n, int i, vector<vector<int>> &v, vector<int> &tmp)
{
    if (i == n)
    {

        v.push_back(tmp);
        return;
    }

    tmp.push_back(a[i]);
    find(a, n, i + 1, v, tmp);
    tmp.pop_back();
    find(a, n, i + 1, v, tmp);

    return;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int count = 0;
        int n;
        int k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        vector<vector<int>> v;
        vector<int> tmp;

        find(a, n, 0, v, tmp);
        for (int i = 0; i < v.size(); i++)
        {
            int sum = 0;
            sum = accumulate(v[i].begin(), v[i].end(), 0);
            if (sum == k)
            {
                count++;
            }
        }

        cout << count << endl;
    }

    // write your code here
    return 0;
}