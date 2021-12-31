#include <bits/stdc++.h>
using namespace std;
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int s, d;
        cin >> s >> d;

        vector<int> ss(d, 0);
        // ss[0]=1;

        int req = s - 1;
        int i = d - 1;
        while (req > 9 && i > 0)
        {
            req -= 9;
            ss[i] = 9;
            i--;
        }
        if (req && i > 0)
        {
            ss[i] = req;

            req = 0;
        }
        ss[0] = req + 1;

        for (int i = 0; i < d; i++)
        {
            cout << ss[i];
        }
        cout << endl;
    }

    return 0;
}