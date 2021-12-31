#include<bits/stdc++.h>
using namespace std;
void build(int*a,int*tree ,int  start,int end,int treenode){
    if(start==end){
        tree[treenode]=a[start];
        return;
    }
    
    int mid=(start+end)/2;
    build(a,tree,start,mid,2*treenode);
    build(a,tree,mid+1,end,2*treenode+1);
    tree[treenode]=max(tree[2*treenode],tree[2*treenode+1]);
    return;
    
}
int query(int *tree,int start,int end,int treenode,int left,int right){
    if(start>right||end<left){
        return 0;
    }
    if(start>=left && end<=right){
        return tree[treenode];
    }
    int ans;
    int mid=(start+end)/2;
    int ans1= query(tree,start,mid,2*treenode,left,right);
     int ans2=query(tree,mid+1,end,2*treenode+1,left,right);
      
       return ans=max(ans1,ans2);
    
    }
int main(){
   int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int tree[4*n];
    build(a,tree,0,n-1,1);
    int q;
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        cout<<query(tree,0,n-1,1,l,r)<<"\n";
    }
    
   
    return 0;
}