// Monk and the Islands

// Monk visits the land of Islands. There are a total of N islands numbered from 1 to N.
// Some pairs of islands are connected to each other by Bidirectional bridges running over water.
// Monk hates to cross these bridges as they require a lot of efforts. He is standing at Island #1
// and wants to reach the Island #N. Find the minimum the number of bridges that he shall have to cross, 
// if he takes the optimal route.
    
// Input format:
// First line contains T. T testcases follow.
// First line of each test case contains two space-separated integers N, M.
// Each of the next M lines contains two space-separated integers X and Y ,
// denoting that there is a bridge between Island X and Island Y.
    
// Output format:
// Print the answer to each test case in a new line.
    
// Constraints:
// 1 ≤ T ≤ 10
// 1 ≤ N ≤ 10000
// 1 ≤ M ≤ 100000
// 1 ≤ X, Y ≤ N

// Sample Input
// 2
// 3 2
// 1 2
// 2 3
// 4 4
// 1 2
// 2 3
// 3 4
// 4 2
    
// Sample Output
// 2
// 2


#include<bits/stdc++.h>
using namespace std;


int dfs(vector<vector<int>>& v ,int n,int ele,  vector<int>& dist){
  queue<int> q;
    q.push(ele);
    dist[ele] = 0;
    while(!q.empty()){
      int x= q.front();
        q.pop();
        
        for(auto it : v[x]){
            if(dist[it]== -1){
                q.push(it);
                dist[it]= dist[x] +1;
                if(it==n-1){
                    return dist[it];
                }
            }
            
            
        }
        
        
        
        
        
    }
    return dist[n-1];
    
    
}
int main(){
  int t;
    cin>>t;
    while(t--){
         int n,m;
       
        cin>>n>>m;
        vector<vector<int>> v(n);
        while(m--){
            int sv,ev;
            cin>>sv>>ev;
            v[sv-1].push_back(ev-1);
            v[ev-1].push_back(sv-1);
            
        }
     vector<int> visited(n,-1);
       
        cout<<dfs(v,n,0,visited)<<endl;
        
        
        
        
        
        
    }
    
  
    return 0;
}
