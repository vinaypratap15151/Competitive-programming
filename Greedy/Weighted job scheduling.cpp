
#include <bits/stdc++.h>
using namespace std;
void printer(int *arr, int n)
{
    int flag = 0;
    for (int i = 0; i < n - 2; i++)
    {
        if (arr[i + 2] + arr[i + 1] <= arr[i])
            continue;
        cout << arr[i + 2] << " " << arr[i + 1] << " " << arr[i] << endl;
        flag = 1;
        break;
    }
    if (!flag)
    {
        cout << -1 << endl;
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        sort(arr, arr + n);
        reverse(arr, arr + n);
        printer(arr, n);
    }
    return 0;
}