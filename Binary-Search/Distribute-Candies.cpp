// Shaky has N (1<=N<=50000) candy boxes each of them contains a non-zero number of candies (between 1 and 1000000000). 
//     Shaky want to distribute these candies among his K (1<=K<=1000000000) IIIT-Delhi students. He wants to distribute them in a way such that:

// 1. All students get an equal number of candies.
// 2. All the candies which a student gets must be from a single box only.
// As he wants to make all of them happy so he wants to give as many candies as possible. Help Shaky in finding out what is the maximum number of candies which a student can get.
    
// Input
// First-line contains T the number of test cases. 
// The first line of each test case contains N and K.
// Next line contains N space-separated integers, ith of which is the number of candies in the ith box.
    
// Output
// For each test case print the required answer in a separate line.
    
// Constraints
// 1<= T <= 10^5
// 1 <= N <= 10^5
// 1 <= K <= 10^9
// 0 <= A[i] <= 10^9
// Sum of N over all test cases doesn't exceed 10^6
    
// Sample Input:
// 2
// 3 2 
// 3 1 4
// 4 1
// 3 2 3 9
// Sample Output:
// 3
// 9

#include <bits/stdc++.h>
using namespace std;
bool check(int mid, vector<long long> v, int n, int k)
{
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += (v[i] / mid);
    }
    if (ans >= k)
    {
        return true;
    }
    return false;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, k;
        cin >> n >> k;
        vector<long long> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }

        sort(v.begin(), v.end());
        int anss = 0;
        int s = 0;
        int e = v[n - 1];
        while (s <= e)
        {
            int mid = (s + e) / 2;
            if (check(mid, v, n, k))
            {
                anss = mid;
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
        }
        cout << anss << endl;
    }
    return 0;
}
