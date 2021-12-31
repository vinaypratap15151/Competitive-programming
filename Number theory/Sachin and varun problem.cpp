#include<bits/stdc++.h>
using namespace std;
long long gcd(long long a,long long b){
    if(b==0) return a;
    return gcd(b,a%b);
}
int main(){
    
    int t;
    cin>>t;
    while(t--){
        long long a;
        cin>>a;
        string s;
        cin>>s;
        long long num=0;
        for(int i=0;i<s.size();i++){
            num=(num*10 + (s[i]-'0'))%a;
            
        }
        cout<<gcd(num,a)<<endl;
    }
    return 0;
}