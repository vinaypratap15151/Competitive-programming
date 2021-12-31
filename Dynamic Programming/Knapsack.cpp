
#include <bits/stdc++.h>
#include <utility>
using namespace std;
pair<int, int> most_fun(int *enterance_fees, int *fun, int budget, int n, pair<int, int> **dp)
{
    pair<int, int> option1 = {INT_MIN, INT_MIN};
    pair<int, int> option2 = {INT_MIN, INT_MIN};
    if (n == 0)
    {
        pair<int, int> p;
        p.first = 0;
        p.second = 0;
        return p;
    }
    if (dp[budget][n].first != -1 && dp[budget][n].second != -1)
    {
        return dp[budget][n];
    }
    pair<int, int> ans;
    if (enterance_fees[0] <= budget)
    {
        option1 = most_fun(enterance_fees + 1, fun + 1, budget - enterance_fees[0], n - 1, dp);
        option1.first += enterance_fees[0];
        option1.second += fun[0];
    }
    option2 = most_fun(enterance_fees + 1, fun + 1, budget, n - 1, dp);
    if (option1.second > option2.second)
    {
        ans = option1;
    }
    else if (option2.second > option1.second)
    {
        ans = option2;
    }
    else
    {
        if (option1.first < option2.first)
        {
            ans = option1;
        }
        else
        {
            ans = option2;
        }
    }

    dp[budget][n] = ans;
    return ans;
}
int main()
{

    int budget;
    int n; // number of parties
    cin >> n;

    int *enterance_fees = new int[n];
    int *fun = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> enterance_fees[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> fun[i];
    }
    cin >> budget;

    // dp
    pair<int, int> **dp = new pair<int, int> *[budget + 1];
    for (int i = 0; i < budget + 1; i++)
    {
        dp[i] = new pair<int, int>[n + 1];
        for (int j = 0; j < n + 1; j++)
        {
            dp[i][j].first = -1;
            dp[i][j].second = -1;
        }
    }

    pair<int, int> p;
    p = most_fun(enterance_fees, fun, budget, n, dp);
    cout << p.first << ' ' << p.second << endl;

    for (int i = 0; i < budget + 1; i++)
    {
        delete[] dp[i];
    }
    delete[] dp;
}
