#include <bits/stdc++.h>
using namespace std;
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n, i;
        cin >> n >> i;
        int m = n & (~(1 << i));
        cout << m << endl;
    }
    return 0;
}