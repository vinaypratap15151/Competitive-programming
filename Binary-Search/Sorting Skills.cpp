#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int flag = 1;
        for (int i = 0; i < n - 1; i++)
        {
            if (a[i] > a[i + 1])
            {
                if (a[i] - a[i + 1] == 1)
                {
                    swap(a[i], a[i + 1]);
                }
                else
                {
                    flag = 0;
                    cout << "No" << endl;
                    break;
                }
            }
        }
        if (flag)
        {
            cout << "Yes" << endl;
        }
    }

    return 0;
}