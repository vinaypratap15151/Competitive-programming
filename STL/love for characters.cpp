#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int count1 = 0, count2 = 0, count3 = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'a')
        {
            count1++;
        }

        else if (s[i] == 's')
        {
            count2++;
        }

        else if (s[i] == 'p')
        {
            count3++;
        }
        else
        {
            continue;
        }
    }
    cout << count1 << " " << count2 << " " << count3;

    return 0;
}
