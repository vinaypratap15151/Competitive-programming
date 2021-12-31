#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
#include <functional> // for less
#include<bits/stdc++.h>
using namespace std;
using namespace __gnu_pbds;

 
// a new data structure defined. Please refer below
// GNU link : https://goo.gl/WVDL6g
typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    pb;
pb s;
void ins(int value){
    s.insert(value);
}
void del(int value){
    auto it=s.find(value);
    if(it!=s.end()){
        s.erase(it);
    }
    
}
void find1(int value){
  if(s.size()>=value)
   cout<< *s.find_by_order(value-1)<<"\n";
    else cout<<"invalid"<<"\n";
}
void find2(int value){
    cout<<s.order_of_key(value)<<"\n";
}
int main(){
    int q;
    cin>>q;
    while(q--){
      char type;
        cin>>type;
        if(type=='I'){
            int value;
            cin>>value;
            ins(value);
        }
        else if(type=='D'){
            int value;
            cin>>value;
            del(value);
        }
        else if(type=='K'){
            int value;
            cin>>value;
            find1(value);
        }
        else{
            int value;
            cin>>value;
            find2(value);
        }
    }
    // write your code here
    return 0;
}