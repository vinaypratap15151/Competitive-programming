#include <bits/stdc++.h>
using namespace std;
void replace(char s[], char, char);
int main()
{

    // write your code here

    int t;
    cin >> t;
    while (t--)
    {
        char s[100];
        char c1, c2;
        cin >> s >> c1 >> c2;

        replace(s, c1, c2);

        cout << s << endl;
    }

    return 0;
}

void replace(char s[], char c1, char c2)
{
    if (s[0] == '\0')
    {
        return;
    }

    if (s[0] == c1)
    {
        s[0] = c2;
    }
    replace(s + 1, c1, c2);
}