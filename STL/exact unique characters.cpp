#include <unordered_map>
#include <math.h>
#include <vector>
using namespace std;
string uniqueChar(string str)
{
    // Write your code here
    if (str.length() == 0 || str.length() == 1)
    {
        return str;
    }

    string ss;
    unordered_map<char, bool> m;

    for (int i = 0; i < str.size(); i++)
    {

        if (!m.count(str[i]))
        {
            m[str[i]] = true;

            ss += str[i];
        }
    }

    return ss;
}