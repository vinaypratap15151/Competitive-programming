#include <bits/stdc++.h>
using namespace std;
int main()
{

    // write your code here
    int t;
    cin >> t;
    while (t--)
    {

        long long a;
        cin >> a;
        string b;
        cin >> b;
        int m;
        cin >> m;

        int l = b.length();
        int i = l - 1;
        long long ans = 1;
        while (i >= 0)
        {

            if (b[i] == '1')
            {
                ans = (ans * a) % m;
            }

            if (b[i] == '2')
            {
                ans = (((ans * a) % m) * a) % m;
            }

            a = (((a * a) % m) * a) % m;
            i--;
        }

        cout << ans << "\n";
    }
    return 0;
}