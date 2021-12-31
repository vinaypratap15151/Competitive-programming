#include<bits/stdc++.h>
#include<math.h>
using namespace std;

#define line                  "\n"
#define all(x)                x.begin(),x.end()

// struct custom_hash {static uint64_t splitmix64(uint64_t x) {x += 0x9e3779b97f4a7c15; x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9; x = (x ^ (x >> 27)) * 0x94d049bb133111eb; return x ^ (x >> 31);} size_t operator()(uint64_t x) const {static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count(); return splitmix64(x + FIXED_RANDOM);}};


vector<vector<int> > adj; int e1, e2; int N, M;
//#define int                long long int


int gcd(int a, int b); int lcm(int a, int b); int CEIL(int a, int b); int power_mod(int a, int b, int mod);

/*

*/
const int MAXN = 1e4;

int n, t[4 * MAXN];
int *a;

void build(int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
        return;
    }
    int tm = (tl + tr) / 2;
    build(2 * v, tl, tm);
    build(2 * v + 1, tm + 1, tr);

    t[v] = gcd(t[2 * v], t[2 * v + 1]);
}


int segGCD(int v, int tl, int tr, int l, int r) {
    if(tl>r||tr<l) return 0;
    if(tl>=l && tr<=r){
        return t[v];
    }

    int tm = (tl + tr) / 2;


    return gcd(segGCD(2 * v, tl, tm, l, r),
               segGCD(2 * v + 1, tm + 1,tr,  l, r));

}




void solve() {
    cin >> n;
    a = new int[n];
    for (int i = 0; i < n; i++)cin >> a[i];

    build(1, 0, n - 1);

    unordered_map<int, int> mp;

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            mp[segGCD(1, 0, n - 1, i, j)]++;
        }
    }
    int q;
    cin >> q;
    int x;
    while (q--) {
        cin >> x;
      
            cout << mp[x] << "\n";
      
    }

}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  
        // cout << "Case #" << i << ": ";
        solve();
    

    return 0;
}

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    return (a / gcd(a, b)) * b;
}
int CEIL(int a, int b) {
    return (a + b - 1) / b;
}

//THINGS I RARELY USE

/*
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds_set;

/*
find_by_order(k):
Desc: returns element present at index K.
Return type: an iterator(use * to decode it)

order_by_key(K):
Desc: returns number of elements which are strictly less than K.
Return type: an integer
*/


// int power_mod(int x, int y, int mod) {

//     int res = 1;
//     x = x % mod;
//     while (y > 0) {
//         if (y & 1)
//             res = (res * x) % mod;
//         y = y >> 1;
//         x = (x * x) % mod;
//     }
//     return res;
// }

