#include<bits/stdc++.h>
using namespace std;
int mex(int a, int b ,int c){
    int value=0;
    while(a==value or b==value or c==value){
        value++;
    }
   return value;
    
    
}
int find(int n,vector<int>&grandy){
    if(n==0) return 0;
   
    int a = find(floor(n/2),grandy);
      int b = find(floor(n/3),grandy);
      int c = find(floor(n/6),grandy);
   return grandy[n] =mex(a,b,c);
    
    
}
int main(){
     vector<int> grandy(1000001,-1);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
      
        
        cout<<find(n,grandy)<<endl;
        
    }
   
    return 0;
}
