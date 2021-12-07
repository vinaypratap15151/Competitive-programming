// Its Gary's birthday today and he has ordered his favourite square cake consisting of '0's and '1's . But Gary wants the biggest piece of '1's and no '0's . 
//  A piece of cake is defined as a part which consist of only '1's, and all '1's share an edge with eachother on the cake. 
// Given the size of cake N and the cake , can you find the size of the biggest piece of '1's for Gary ?
    
// Input Format :
// First line will contain T(number of test cases), each test case follows as.
// Line 1 : An integer N denoting the size of cake 
// Next N lines : N characters denoting the cake

// Output Format :
// Print the size of the biggest piece of '1's and no '0'sfor each test case in a newline.
    
// Constraints:
// 1 <= T <= 10
// 1 <= N <= 1000
    
// Sample Input :
// 1
// 2
// 11
// 01
    
// Sample Output :
// 3









#include <bits/stdc++.h>
using namespace std;

bool isValid(int n, int x, int y)
{
    return (x >= 0 && x < n && y >= 0 && y < n);
}

int helper(vector<vector<int>> &cake, int n, vector<vector<bool>> &visited, int x, int y)
{
    int arr[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
    int ans = 1;
    visited[x][y] = 1;
    for (int i = 0; i < 4; i++)
    {
        int newX, newY;
        newX = x + arr[i][0];
        newY = y + arr[i][1];

        if (isValid(n, newX, newY) && !visited[newX][newY] && cake[newX][newY] == 1)
        {

            ans += helper(cake, n, visited, newX, newY);
        }
    }
    return ans;
}

int getBiggestPieceSize(vector<vector<int>> &cake, int n)
{
    // Write your code here
    vector<vector<bool>> visited(n, vector<bool>(n, 0));

    int overallMax = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (cake[i][j] == 1 && visited[i][j] != 1)
            {
                visited[i][j] = 1;
                int curr = helper(cake, n, visited, i, j);
                overallMax = max(overallMax, curr);
            }
        }
    }
    return overallMax;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vector<vector<int>> cake(n, vector<int>(n));

        for (int i = 0; i < n; ++i)
        {
            string s;
            cin >> s;
            for (int j = 0; j < n; ++j)
            {
                cake[i][j] = s[j] - '0';
            }
        }

        cout << getBiggestPieceSize(cake, n) << endl;
    }
}
