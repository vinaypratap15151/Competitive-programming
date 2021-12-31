#include <bits/stdc++.h>
using namespace std;
long long p = 1e9 + 7;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        string s;
        cin >> s;
        int dp[s.size() + 1];
        dp[0] = 1;
        unordered_map<char, int> m;
        for (int i = 1; i <= s.size(); i++)
        {
            dp[i] = (2 * dp[i - 1]) % p;
            char ch = s[i - 1];
            if (m[ch])
            {
                dp[i] = (dp[i] - dp[m[ch] - 1] + p) % p;
            }
            m[ch] = i;
        }
        cout << (dp[s.size()]) % p << endl;
    }

    return 0;
}