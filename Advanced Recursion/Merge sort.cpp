#include <bits/stdc++.h>
using namespace std;
void mergesort(int a[], int, int, int);
void merge(int a[], int s, int e, int);
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        // write your code here
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        mergesort(a, 0, n - 1, n);
        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }

    return 0;
}

void mergesort(int a[], int s, int e, int n)
{
    if (s >= e)
    {
        return;
    }

    int mid = (e + s) / 2;
    mergesort(a, s, mid, n);
    mergesort(a, mid + 1, e, n);

    merge(a, s, e, n);
}
void merge(int a[], int s, int e, int n)
{
    int temp[e - s + 1];
    int mid = (s + e) / 2;
    int i = s;
    int j = mid + 1;
    int k = 0;
    while (i <= mid && j <= e)
    {
        if (a[i] < a[j])
        {
            temp[k++] = a[i++];
        }

        else
        {
            temp[k++] = a[j++];
        }
    }

    while (i <= mid)
    {
        temp[k++] = a[i++];
    }

    while (j <= e)
    {
        temp[k++] = a[j++];
    }

    for (int i = s, k = 0; i <= e; i++, k++)
    {

        a[i] = temp[k];
    }
}