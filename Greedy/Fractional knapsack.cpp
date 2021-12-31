#include <bits/stdc++.h>
using namespace std;
bool arrange(vector<int> v1, vector<int> v2)
{
    return v1[1] < v2[1];
}
int main()
{

    int n;
    cin >> n;
    vector<vector<int>> jobs(n, vector<int>(3));
    for (int i = 0; i < n; i++)
    {

        cin >> jobs[i][0] >> jobs[i][1] >> jobs[i][2];
    }

    sort(jobs.begin(), jobs.end(), arrange);

    vector<int> profits(n);
    profits[0] = jobs[0][2];
    for (int i = 1; i < n; i++)
    {
    }

    cout << profits[n - 1];

    return 0;
}