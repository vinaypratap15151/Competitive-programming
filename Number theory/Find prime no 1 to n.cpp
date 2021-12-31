#include <bits/stdc++.h>
using namespace std;
int find(int x, int y)
{
    if (y == 0)
        return x;
    return find(y, x % y);
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
    return 0;
}