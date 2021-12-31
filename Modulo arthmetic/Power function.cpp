#include <bits/stdc++.h>
using namespace std;
int find(int x, int y)
{
    long ans = 1;
    int m = 1e9 + 7;
    for (int i = 1; i <= y; i++)
    {

        ans = (ans * x) % m;
    }

    return ans;
}
int main()
{

    int t;
    cin >> t;
    while (t--)
    {

        int x, y;
        cin >> x >> y;

        cout << find(x, y) << endl;
    }

    // write your code here
    return 0;
}