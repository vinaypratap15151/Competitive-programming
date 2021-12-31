#include<bits/stdc++.h>
void rotate(int *input, int d, int n)
{
    //Write your code here
    vector<int> v;

    
    for(int i=0;i<d;i++){
        v.push_back(input[i]);
    }    
    
    for(int i=d;i<n;i++){
        
        input[i-d]=input[i];
        
        
    }
    int j=0;
    for(int i=n-d;i<n;i++ ){
        input[i]=v[j];
        j++;
    }
    
    
    
}