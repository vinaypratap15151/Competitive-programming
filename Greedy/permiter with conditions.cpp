#include <bits/stdc++.h>
using namespace std;
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;

        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        sort(a, a + n);
        int initial_ans = a[n - 1] - a[0];
        int small = a[0] + k;
        int big = a[n - 1] - k;

        if (small > big)
        {
            swap(small, big);
        }

        for (int i = 1; i < n - 1; i++)
        {
            int subt = a[i] - k;
            int add = a[i] + k;
            if (subt >= small || add <= big)
            {
                continue;
            }

            if (big - subt < add - small)
            {
                small = subt;
            }
            else
            {
                big = add;
            }
        }
        int final_ans = big - small;
        int ans = min(initial_ans, final_ans);
        cout << ans << endl;
    }
    return 0;
}