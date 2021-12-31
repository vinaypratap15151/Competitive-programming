
#include <bits/stdc++.h>
using namespace std;
int main()
{
    // Write your code here

    string s;
    getline(cin, s);

    stringstream ss(s);
    string word;

    unordered_map<string, int> m;

    while (ss >> word)
    {
        m[word]++;
    }

    for (auto it = m.begin(); it != m.end(); it++)
    {

        if (it->second > 1)
        {

            cout << it->first << " " << it->second << endl;
        }
    }

    return 0;
}