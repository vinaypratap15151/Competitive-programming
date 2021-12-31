#include<bits/stdc++.h>
using namespace std;
struct node{
    int even;
    int odd;
};
void build(int*a,node*tree ,int  start,int end,int treenode){
    if(start==end){
        if(a[start]%2==0){
        tree[treenode].even=1;
        tree[treenode].odd=0;}
        else{
        tree[treenode].even=0;
        tree[treenode].odd=1;
        }
        return;
    }
    
    int mid=(start+end)/2;
    build(a,tree,start,mid,2*treenode);
    build(a,tree,mid+1,end,2*treenode+1);
    tree[treenode].even=tree[2*treenode].even + tree[2*treenode+1].even;
    tree[treenode].odd =tree[2*treenode].odd + tree[2*treenode+1].odd;

    
}
void update(int*a ,node*tree ,int start,int end,int treenode,int idx, int value){
    
    if(start==end){
        a[idx]=value;
       if (value % 2 == 0)
		{
			tree[treenode].even = 1;
			tree[treenode].odd = 0;
		}
		else
		{
			tree[treenode].even = 0;
			tree[treenode].odd = 1;
		}
        return;
    }
    
    int mid=(start+end)/2;
    if(idx>mid){
        update(a,tree,mid+1,end,2*treenode+1,idx,value);
    }
    else{
        update(a,tree,start,mid,2*treenode,idx,value);
    }
    
    tree[treenode].even = tree[2 * treenode].even + tree[2 * treenode + 1].even;
	tree[treenode].odd = tree[2 * treenode].odd + tree[2 * treenode + 1].odd;
    
    
    
}
node query(node *tree,int start,int end,int treenode,int left,int right){
    if(start>right||end<left){
        node result;
        result.odd=0;
        result.even=0;
        return result;
    }
    if(start>=left && end<=right){
        return tree[treenode];
    }
    node ans;
    int mid=(start+end)/2;
    node ans1= query(tree,start,mid,2*treenode,left,right);
    node ans2=query(tree,mid+1,end,2*treenode+1,left,right);
      ans.even= ans1.even + ans2.even;
      ans.odd =ans1.odd + ans2.odd;
    return ans;
      
    
    }
int main(){
   int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    node*tree=new node[4*n];
    build(a,tree,0,n-1,1);
    int q;
    cin>>q;
    while(q--){
        int type;
        cin>>type;
        if(type==0){
            int i,value;
            cin>>i>>value;
        update(a,tree,0,n-1,1,i-1,value);
        }
       else if(type==1){
            int x,y;
            cin>>x>>y;
            cout<<query(tree,0,n-1,1,x-1,y-1).even<<"\n";
        }
        else{
            int x,y;
            cin>>x>>y;
            cout<<query(tree,0,n-1,1,x-1,y-1).odd<<"\n";
        }
        
    }
    
   
    return 0;
}