#include <bits/stdc++.h>
using namespace std;

class triplet
{
public:
    int x;
    int y;
    int gcd;
};
triplet gcdext(int a, int b)
{
    if (b == 0)
    {
        triplet ans;
        ans.gcd = a;
        ans.x = 1;
        ans.y = 0;
        return ans;
    }
    triplet smallans = gcdext(b, a % b);
    triplet ans;
    ans.gcd = smallans.gcd;
    ans.x = smallans.y;
    ans.y = smallans.x - (a / b) * smallans.y;

    return ans;
}
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int modinverse(int A, int M)
{
    int x = gcdext(A, M).x;
    return (x % M + M) % M;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        long long a, b, d;
        cin >> a >> b >> d;
        long long g = gcd(a, b);
        if (d % g)
        {
            cout << "0" << endl;
            continue;
        }
        a /= g;
        b /= g;
        d /= g;

        long long y1 = ((d % a) * modinverse(b, a)) % a;
        long long firstvalue = (d / b);
        if (d < y1 * b)
        {
            cout << "0" << endl;
            continue;
        }
        long long n = (firstvalue - y1) / a;
        cout << (n + 1) << endl;
    }

    return 0;
}