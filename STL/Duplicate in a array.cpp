
#include<bits/stdc++.h>
int findDuplicate(int *arr, int n)
{
    //Write your code here
    unordered_map<int ,int> m;
    
    for(int i=0;i<n;i++){
        m[arr[i]]++;
        
        
        
    }
    
    for(int i=0;i<n;i++){
        
        if(m[arr[i]]==2){
            return arr[i];
        }
    }
    
    
    
}