#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int MAX=100005;
int bit[100005];
struct ele{
    ll value;
    int index;
};
struct Query{
    int l;
    int r;
    ll k;
    int index;
};

bool compare(ele a ,ele b){
    return a.value> b.value;
}

bool comp(Query a,Query b){
    return a.k>b.k;
}
void update(int index,int value){
    for(;index<MAX;index+=(index&(-index))){
        bit[index]+=value;
    }
}
int query(int index){
    int ans=0;
    
    for(;index>0;index-=(index&(-index))){
        ans+=bit[index];
    }
    return ans;
}

int main(){
  int n,q;
    cin>>n;
    ele a[n+1];
   
    
    for(int i=1;i<=n;i++){
        cin>>a[i].value;
        a[i].index=i;
    }
    sort(a+1,a+n+1,compare);
    cin>>q;
  Query Q[q+1];
    ll ans[q+2];
       
    for(int i=0;i<q;i++){
        cin>>Q[i].l>>Q[i].r>>Q[i].k;
        Q[i].index=i;
    }
    sort(Q,Q+q,comp);
    int z=1;
    for(int i=0;i<q;i++){
        while(z<=n && Q[i].k<a[z].value){
            update(a[z].index,1);
            z++;
        }
        ans[Q[i].index]=query(Q[i].r) -query(Q[i].l-1);
    }
    for(int i=0;i<q;i++){
        cout<<ans[i]<<endl;
    }
    
    return 0;
}s