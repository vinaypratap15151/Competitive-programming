#include <bits/stdc++.h>
using namespace std;

long product(int n)
{
    if (n == 1)
    {
        return n;
    }
    long m = pow(10, 9) + 7;
    long x = product(n - 1);
    long y = n;

    long ans1 = x % m;
    long ans2 = y % m;
    long ans = (ans1 * ans2) % m;
    return ans;
}
int main()
{

    // write your code here
    int t;
    cin >> t;
    while (t--)
    {

        int n;
        cin >> n;
        cout << product(n) << endl;
    }

    return 0;
}