#include <bits/stdc++.h>
using namespace std;

int max_so_far;

int kadane(int left, int right, int n, int m, vector<int> &temp, int **mat)
{

    int sum = 0;
    int max_sum = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        sum += temp[i];
        if (sum < 0)
        {
            sum = 0;
        }
        max_sum = max(max_sum, sum);
    }
    if (max_sum > max_so_far)
    {
        max_so_far = max_sum;
    }
    return max_so_far;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n, m;
        cin >> n >> m;
        int temp[n];
        int **mat = new int *[n + 1];
        for (int i = 0; i < n + 1; i++)
        {
            mat[i] = new int[m + 1];
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> mat[i][j];
            }
        }
        int ans = 0;
        max_so_far = INT_MIN;
        for (int left = 0; left < m; left++)
        {
            vector<int> temp(n, 0);
            for (int right = left; right < m; right++)
            {
                for (int i = 0; i < n; i++)
                {
                    temp[i] += mat[i][right];
                }
                ans = kadane(left, right, n, m, temp, mat);
            }
        }

        cout << ans << endl;
    }

    return 0;
}