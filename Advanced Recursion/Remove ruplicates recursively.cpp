#include <bits/stdc++.h>
using namespace std;

string remove(string s)
{
    if (s.size() == 0 || s.size() == 1)
    {
        return s;
    }

    if (s[0] == s[1])
    {
        s.erase(s.begin());
        return remove(s);
    }

    else
    {
        return s[0] + remove(s.substr(1));
    }
}

int main()
{

    // write your code here
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;

        cout << remove(s) << endl;
    }

    return 0;
}
