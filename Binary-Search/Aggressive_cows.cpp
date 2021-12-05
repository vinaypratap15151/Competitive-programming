/*                         _
                        _ooOoo_
                       o8888888o
                       88" . "88
                       (| -_- |)
                       O\  =  /O
                    ____/`---'\____
                  .'  \\|     |//  `.
                 /  \\|||  :  |||//  \
                /  _||||| -:- |||||_  \
                |   | \\\  -  /'| |   |
                | \_|  `\`---'//  |_/ |
                \  .-\__ `-. -'__/-.  /
              ___`. .'  /--.--\  `. .'___
           ."" '<  `.___\_<|>_/___.' _> \"".
          | | :  `- \`. ;`. _/; .'/ /  .' ; |
          \  \ `-.   \_\_`. _.'_/_/  -' _.' /
===========`-.`___`-.__\ \___  /__.-'_.'_.-'================
 
                  Please give me AC.
*/

#include <bits/stdc++.h>
using namespace std;

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
#define endl "\n"
#define gc getchar_unlocked
#define fo(i, n) for (int i = 0; i < n; i++)
#define Fo(i, k, n) for (i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define ll long long
#define si(x) scanf("%d", &x)
#define sl(x) scanf("%lld", &x)
#define ss(s) scanf("%s", s)
#define pi(x) printf("%d\n", x)
#define pl(x) printf("%lld\n", x)
#define ps(s) printf("%s\n", s)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
bool check(int c,int mid,ll*a, int n){
    ll last_position= a[0];
    c--;
    while(last_position+mid<=a[n-1]){
        c--;
        last_position=last_position+mid;
        
        if(!c){
            return true;
        }
    }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int t;
    cin >> t;
    while (t--)
    {
        int n,c;
        cin>>n>>c;
        ll a[n];
        int ans=0;
        fo(i,n) cin>>a[i];
        sort(a,a+n);
        ll s=a[0], e=a[n-1];
        while(s<=e){
            ll mid=(s+e)/2;
            if(check(c,mid,a,n)){
                ans=mid;
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
