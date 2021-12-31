#include<bits/stdc++.h>
using namespace std;
  int power[100001];
void updatepower(){
    power[0]=1;
  for(int i=1;i<100001;i++){
      power[i]=(power[i-1]*2)%3;
  }
}
void build(int*a,int*tree,int start,int end,int treenode){
    if(start==end){
        tree[treenode]=a[start];
        return;
    }
    int left=2*treenode;
    int right=2*treenode+1;
    int mid=(start+end)/2;
    build(a,tree,start,mid,left);
    build(a,tree,mid+1,end,right);
    
    tree[treenode]=(tree[right] + tree[left]*power[end-mid])%3;
    
}
void update(int*a,int*tree,int start,int end,int treenode,int idx){
    if(start==end){
        a[idx]=1;
        tree[treenode]=1;
        return;
    }
    int left=2*treenode;
    int right=2*treenode+1;
    int mid=(start+end)/2;
    if(idx>mid)
     update(a,tree,mid+1,end,right,idx);
    else
           update(a,tree,start,mid,left,idx);

     tree[treenode]=(tree[right] + tree[left]*power[end-mid])%3;
    
}
int query(int*tree,int start,int end,int treenode,int l,int r){
    if(l>end||r<start) return 0;
    if(start>=l && end<=r){
        return (tree[treenode]*power[r-end])%3;
    }
        int left=2*treenode;
    int right=2*treenode+1;
    int mid=(start+end)/2;
    
    int ans1=query(tree,start,mid,left,l,r);
    int ans2=query(tree, mid+1,end,right ,l,r);
    int ans=(ans1+ans2)%3;
    return ans;
    
}

int main(){
    updatepower();
    int n;
    cin>>n;
    int a[n];
    string s;
    cin>>s;
    for(int i=0;i<n;i++){
      a[i]=s[i]-'0';
    }
    int*tree=new int[4*n];
    build(a,tree,0,n-1,1);
    int q;
    cin>>q;
    while(q--){
        int type;
        cin>>type;
        if(type==0){
            int l,r;
            cin>>l>>r;
            cout<<query(tree,0,n-1,1,l,r)<<"\n";
        }
        else{
            int idx;
            cin>>idx;
            if(a[idx]==0)
            update(a,tree,0,n-1,1,idx);
            
        }
    }
    
    return 0;
}