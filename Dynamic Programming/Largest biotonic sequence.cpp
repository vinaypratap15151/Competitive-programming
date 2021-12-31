#include <bits/stdc++.h>
using namespace std;
long long m = 1e9 + 7;
long long find(int n, int steps[])
{

    if (n == 0)
    {
        return 1;
    }
    if (n < 0)
    {
        return 0;
    }

    if (n == 1)
    {
        return 1;
    }
    if (n == 2)
    {
        return 2;
    }

    if (steps[n] != -1)
    {
        return steps[n];
    }

    long long output1 = (find(n - 1, steps) + find(n - 2, steps) + find(n - 3, steps)) % m;
    steps[n] = (output1);

    return steps[n];
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
        int steps[n + 1];
        for (int i = 0; i < n + 1; i++)
        {
            steps[i] = -1;
        }

        cout << (find(n, steps)) % m << endl;
    }

    return 0;
}