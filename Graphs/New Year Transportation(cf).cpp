New Year Transportation

#include<bits/stdc++.h>
using namespace std;
string check(int*a ,int dest,int n){
    
    if(dest==1){
        return "YES";
    }
    int i=1;
  while(i<n){
      if(a[i]==dest) return"YES";
      
      i =a[i];
      
  }
    
    return "NO";
}
int main(){
  int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i=1;i<=n-1;i++){
            cin>>a[i];
        }
        for(int i=1;i<=n-1;i++){
            a[i]= i+a[i];
        }
        
             int q;
        cin>>q;
        while(q--){
            int d;
            cin>>d;
            cout<<check(a,d,n)<<endl;;
        }
            
        
        
    
        
        
        
    }
    return 0;
}
