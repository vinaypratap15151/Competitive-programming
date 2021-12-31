

#include<iostream>
#include<climits>
using namespace std;
class trienode
{
public:
    trienode **children;
    int weight;
    trienode()
    {
        children = new trienode *[26];
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        weight = 0;
    }
};
void insert(string s ,int w ,trienode*root){
    if(s.size()==0) return;
    int index = s[0]-'a';
    trienode*current;
    
    if(root->children[index]!=NULL){
        current= root->children[index];
    }
    else{
        current = new trienode();
        root->children[index] = current;
        
    }
    if(root->weight< w){
        root->weight =w;
    }
    
    insert(s.substr(1), w,current);
       
    
    
}
int search_best(string s, trienode*root){
    int n =s.size();
    trienode*current=root;
    int ans=INT_MIN;
    for(int i=0;i<n;i++){
        int index = s[i]-'a';
          if(current->children[index]!=NULL){
               ans=current->children[index]->weight;
            current = current->children[index];
            
          }
        
        else{
             return -1;
        }
        
        
    }
    
    return ans;
    
}


int main()
{
    int n, q;
    cin>>n>>q;
    trienode*root=new trienode();
    for(int i=0; i<n; i++)
    {
        string s;
        cin>>s;
        int weight;
        cin>>weight;
        insert(s, weight, root);
    }
    while(q--)
    {
        string s;
        cin>>s;
        if(!search_best(s, root)) cout<<"-1"<<endl;
        else cout<<search_best(s, root)<<endl;
    }
    return 0;
}