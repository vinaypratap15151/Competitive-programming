#include<bits/stdc++.h>
using namespace std;

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }

        int*dp=new int[1005];
        int*freq=new int[1005];
        
        for(int i=0;i<1005;i++){
            dp[i]=freq[i]=0;
        }
        
        for(int i=0;i<n;i++){
            freq[a[i]]++;
        }
        
        dp[1]=freq[1];
        for(int i=2;i<=1000;i++){
            dp[i]=max(dp[i-2]+(freq[i]*i), dp[i-1]);
        }
        
        int maximum= dp[1000];
        cout<<maximum<<endl;
       delete[] dp;
        delete[] freq;
        
        
    }
    
    
    return 0;
}