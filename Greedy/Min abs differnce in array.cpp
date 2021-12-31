#include <bits/stdc++.h>
using namespace std;
int main()
{

    // write your code here
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int j = 0;
        long long ans = 0;
        sort(arr, arr + n);
        for (int i = n - 1; i >= 0; i--)
        {
            ans += arr[i] * (pow(2, j));
            j++;
        }

        cout << ans << endl;
    }
    return 0;
}