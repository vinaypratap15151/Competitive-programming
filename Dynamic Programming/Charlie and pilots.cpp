#include<bits/stdc++.h>
using namespace std;
int m=1e9+7;
int find(int n ,int k,int o, int c ,bool*b,int**dp){
    
   if(o>n||c>n) return 0;
    if(o==n&&c==n) return 1;
    if(dp[o][c]!=-1) return dp[o][c];
    int ans;
    if(o==c||b[o+c+1]){  
        ans=find(n,k,o+1,c,b,dp);
    }
    else if(o==n){
        ans=find(n,k,o,c+1,b,dp);
    }
    else{
      int  ans1=find(n,k,o+1,c,b,dp);
         int ans2=find(n,k,o,c+1,b,dp);
        ans=(ans1+ans2)%m;
    }
    dp[o][c]=(ans)%m;
    return ans;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n,k;
        cin>>n>>k;
       bool*a=new bool[2*n+1];
        for(int i=0;i<=2*n;i++){
            a[i]=false;
        }
        for(int i=0;i<k;i++){
            int element;
            cin>>element;
            a[element]=true;
        }
        int**dp= new int*[2*n+1];
        for(int i=0;i<2*n+1;i++){
            dp[i]=new int[2*n+1];
            for(int j=0;j<2*n+1;j++){
                dp[i][j]=-1;
            }
        }
        
        
        cout<<find(n,k,0,0,a,dp)<<endl;
        
        
    }
    
    return 0;
}