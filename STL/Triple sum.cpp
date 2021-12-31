#include<bits/stdc++.h>
int tripletSum(int *arr, int n, int num)
{
	//Write your code here
    int count=0;
    sort(arr,arr+n);
  
    for(int i=0;i<n-2;i++){
        int l=i+1;
        int r=n-1;
        
        while(l<r){
            
            int sumo=arr[i]+arr[l]+arr[r];
            if(sumo==num){
                count++;
            
                
            }
            
            else if(sumo<arr[i]){
                l++;
            }
            
            else
                r--;
            
        }
        
    }
    
    return count;
}