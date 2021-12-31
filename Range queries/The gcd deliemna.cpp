#include<bits/stdc++.h>
using namespace std;
struct coder{
    int x;
    int y;
    int index;
};
bool comp(coder c1, coder c2){
    if(c1.x==c2.x) return c1.y<c2.y;
    return c1.x < c2.x;
}
void update(int y, int*tree){
    for(;y<=100000;y+=(y&(-y))){
        tree[y]++;
    }
}
int query(int y, int*tree){
    int ans=0;
    for(;y>0;y-=(y&(-y))){
        ans+=tree[y];
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    coder*a=new coder[n+1];
    for(int i=0;i<n;i++){
        cin>>a[i].x>>a[i].y;
        a[i].index=i;
    }
    sort(a,a+n,comp);
    int*ans =new int[n+1];
    int*tree =new int[100001];
    for(int i=0;i<n;){
        int endindex=i;
        while(endindex<n && a[i].x==a[endindex].x && a[i].y==a[endindex].y){
            endindex++;
        }
        
        for(int j=i;j<endindex;j++){
            ans[a[j].index] = query(a[j].y ,tree);
        }
        for(int j=i;j<endindex;j++){
            update(a[j].y,tree);
        }
        i=endindex;
        
    }
    for(int i=0;i<n;i++){
        cout<<ans[i]<<"\n";
    }
    
    
    return 0;
}