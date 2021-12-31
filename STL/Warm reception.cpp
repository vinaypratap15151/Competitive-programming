#include <bits/stdc++.h>
using namespace std;
int main()
{

    // Write your code here
    int n;
    cin >> n;
    int a[n];
    int d[n];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> d[i];
    }

    sort(a, a + n);
    sort(d, d + n);

    int count = 1;
    int ans = INT_MIN;
    int j = 0, i = 1;
    while (i < n && j < n)
    {

        if (a[i] <= d[j])
        {
            count++;
            i++;
            ans = max(ans, count);
        }
        else
        {
            count--;
            j++;
        }
    }

    cout << ans;
}