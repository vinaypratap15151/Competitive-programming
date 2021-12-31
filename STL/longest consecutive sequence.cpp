
#include <bits/stdc++.h>
vector<int> longestConsecutiveIncreasingSequence(int *arr, int n)
{
    // Your Code goes here
    vector<int> ans;
    vector<int> v;
    set<int> s;
    for (int i = 0; i < n; i++)
    {
        s.insert(arr[i]);
    }
    for (auto it = s.begin(); it != s.end(); it++)
    {
        v.push_back(*it);
    }
    sort(v.begin(), v.end());

    int maxx = INT_MIN;
    int i = 0;
    int length = 1;
    int j = 0;
    int si, ei;
    while (j < v.size() - 1)
    {
        if (v[j + 1] == v[j] + 1)
        {
            j++;

            length++;
            if (length > maxx)
            {
                maxx = length;
                si = v[i];
                ei = v[j];
            }

            if (length == maxx)
            {
                int *p = find(arr, arr + n, si);
                int *q = find(arr, arr + n, v[i]);

                if ((p - arr) > (q - arr))
                {
                    si = v[i];

                    ei = v[j];
                }
            }
        }
        else
        {
            j++;
            i = j;

            length = 1;
        }
    }

    ans.push_back(si);
    ans.push_back(ei);
    return ans;
}