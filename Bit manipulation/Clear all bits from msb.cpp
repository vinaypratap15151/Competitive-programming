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
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        unordered_map<int, int> m;
        for (int i = 0; i < n; i++)
        {
            m[a[i]]++;
        }

        for (int i = 0; i < n; i++)
        {
            if (m[a[i]] % 2 != 0)
            {
                cout << a[i] << endl;
                break;
            }
        }
    }
    return 0;
}