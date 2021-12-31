#include <bits/stdc++.h>
using namespace std;
void quicksort(int a[], int, int, int);
int partition(int a[], int, int, int);
int main()
{

    // write your code here
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

        quicksort(a, 0, n - 1, n);
        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }
    return 0;
}

void quicksort(int a[], int s, int e, int n)
{

    if (s >= e)
    {
        return;
    }
    int ele = partition(a, s, e, n);
    quicksort(a, s, ele - 1, n);
    quicksort(a, ele + 1, e, n);
}

int partition(int a[], int s, int e, int n)
{

    int i = s;

    int piv = a[e];

    for (int j = s; j < e; j++)
    {

        if (a[j] < piv)
        {
            swap(a[i], a[j]);
            i++;
        }
    }

    swap(a[i], a[e]);
    return i;
}
