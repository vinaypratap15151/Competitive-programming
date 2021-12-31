#include<bits/stdc++.h>
using namespace std;
struct node{
    int idx;//index value
    int s;// strength value
    int c; //cowardise value
};
void build(int*a,int*b,node*tree ,int  start,int end,int treenode){
    if(start==end){
        tree[treenode].idx=start;
        tree[treenode].s = a[start];
        tree[treenode].c =b[start];
        return;
    }
    
    int mid=(start+end)/2;
    build(a,b,tree,start,mid,2*treenode);
    build(a,b,tree,mid+1,end,2*treenode+1);
  if(tree[2*treenode].s!=tree[2*treenode+1].s){ // if strength value is differnt then choose max one
      if(tree[2*treenode].s>tree[2*treenode+1].s){
          tree[treenode].s=tree[2*treenode].s;
          tree[treenode].idx=tree[2*treenode].idx;
          tree[treenode].c =tree[2*treenode].c;
      }
      else{
           tree[treenode].s=tree[2*treenode+1].s;
          tree[treenode].idx=tree[2*treenode+1].idx;
          tree[treenode].c =tree[2*treenode +1 ].c;
          
      }
      
      
  }
    
    else if(tree[2*treenode].c!=tree[2*treenode+1].c){ // if strength is same but cowardise isnt so choose minimum
            if(tree[2*treenode].c<tree[2*treenode+1].c){
                 tree[treenode].s=tree[2*treenode].s;
          tree[treenode].idx=tree[2*treenode].idx;
          tree[treenode].c =tree[2*treenode].c;
            }
            else{
                 tree[treenode].s=tree[2*treenode+1].s;
          tree[treenode].idx=tree[2*treenode+1].idx;
          tree[treenode].c =tree[2*treenode +1 ].c;
          
                
            }
            
        }
    
        else{   //if both of above are same then choose minimum index which will be always left one
            
                 tree[treenode].s=tree[2*treenode].s; 
          tree[treenode].idx=tree[2*treenode].idx;
          tree[treenode].c =tree[2*treenode].c;
            
           
        }
        
    
    
}
node query(node *tree,int start,int end,int treenode,int left,int right){
    if(start>right||end<left){
        return {INT_MAX,0,INT_MAX};
    }
    if(start>=left && end<=right){
        return tree[treenode];
    }
    node ans;
    int mid=(start+end)/2;
    node ans1= query(tree,start,mid,2*treenode,left,right);
     node ans2=query(tree,mid+1,end,2*treenode+1,left,right);
      
    
    if(ans1.s!=ans2.s){
      if(ans1.s>ans2.s){
          return ans1;
      }
    
      
  }
    
    else if(ans1.c!=ans2.c){
            if(ans1.c<ans2.c){
                return ans1;
            }
           
            
        }
    
        else if(ans1.idx<ans2.idx){
            
                return ans1;}
           
        
         
    
       return ans2;
    
    }
int main(){
   int n;
    cin>>n;
    int strength[n];
    for(int i=0;i<n;i++){
        cin>>strength[i];
    }
    int coward[n];
    for(int i=0;i<n;i++){
        cin>>coward[i];
    }
    node*tree=new node[4*n];
    build(strength,coward,tree,0,n-1,1);
    int q;
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        cout<<query(tree,0,n-1,1,l-1,r-1).idx+1<<"\n";
    }
    
   
    return 0;
}