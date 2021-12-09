#include <bits/stdc++.h>
using namespace std;
bool check(long long, long long);
int main()
{

    // write your code here
    int t;
    cin >> t;
    while (t--)
    {

        long long n;
        cin >> n;
        long long s = 1;
        long long e = n;
        long long ans = 0;
        while (e >= s)
        {
            long long mid = (e + s) / 2;
            if (check(mid, n))
            {
                ans = mid;
                e = mid - 1;
            }

            else
            {
                s = mid + 1;
            }
        }

        cout << ans << endl;
    }

    return 0;
}

bool check(long long k, long long n)
{
    long long sum = 0;
    long long in = n;
    while (in > 0)
    {
        sum += min(in, k);
        in = in - k;
        in = in - (in / 10);
    }

    if ((2 * sum) >= n)
    {
        return true;
    }

    return false;
}