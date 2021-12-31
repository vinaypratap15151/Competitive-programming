#include <bits/stdc++.h>

int pairSum(int *arr, int n)
{
    // Write your code here
    int count = 0;
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        m[arr[i]]++;
    }

    for (int i = 0; i < n; i++)
    {

        count += m[0 - arr[i]];

        if (0 - arr[i] == arr[i])
        {
            count--;
        }
    }

    return count / 2;
}