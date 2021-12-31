

#include<iostream>
#include<utility>
#include<algorithm>
#include<climits>
using namespace std;

pair<int,int> query(pair<int,int>* tree, int start, int end, int treeNode, int left, int right){
	
	//Completely out
	if (left>end || right<start)
	{
		pair<int,int> temp = make_pair(INT_MIN, INT_MIN);
		return temp;
	}

	//Completely inside
	if (start>=left && end<=right)
	{
		return tree[treeNode];
	}

	//Partially inside
	int mid = (start+end)/2;

	pair<int,int> l = query(tree, start, mid, 2*treeNode+1, left, right);
	pair<int,int> r = query(tree, mid+1, end, 2*treeNode+2, left, right);


	  pair<int, int> l = tree[2*treeNode+1];
	pair<int, int> r = tree[2*treeNode+2];
    vector<int> v(4);
    

	 v[0]=l.first;
    v[1]=l.second;
    v[2]=r.first;
    v[3]=r.second;
int pos=*max_element(v.begin(),v.end());

	tree[treeNode].first = v[pos];
    v[pos]=0;
     int ss=*max_element(v.begin(),v.end());
	tree[treeNode].second = v[ss];
    return;
}


void update(int* arr, pair<int,int>* tree, int start, int end, int treeNode, int idx, int value){
	int mid = (start+end)/2;

	if (start == end)
	{
		arr[idx] = value;
		tree[treeNode] = make_pair(value, INT_MIN);
		return;
	}

	if (idx<=mid)
	{
		update(arr, tree, start, mid, 2*treeNode+1, idx, value);
	}else{

		update(arr, tree, mid+1, end, 2*treeNode+2, idx, value);
	}
    pair<int, int> left = tree[2*treeNode+1];
	pair<int, int> right = tree[2*treeNode+2];
    vector<int> v(4);
    

	 v[0]=left.first;
    v[1]=left.second;
    v[2]=right.first;
    v[3]=right.second;
int pos=*max_element(v.begin(),v.end());

	tree[treeNode].first = v[pos];
    v[pos]=0;
     int ss=*max_element(v.begin(),v.end());
	tree[treeNode].second = v[ss];
    return;
}


void create(int* arr, pair<int,int>* tree, int start, int end, int treeNode){
	if (end == start)
	{
		tree[treeNode] = make_pair(arr[start], INT_MIN);
		return;
	}

	int mid = (start+end)/2;

	create(arr, tree, start, mid, 2*treeNode+1);
	create(arr, tree, mid+1, end, 2*treeNode+2);

	pair<int, int> left = tree[2*treeNode+1];
	pair<int, int> right = tree[2*treeNode+2];
    vector<int> v(4);
    v[0]=left.first;
    v[1]=left.second;
    v[2]=right.first;
    v[3]=right.second;
int pos=*max_element(v.begin(),v.end());

	tree[treeNode].first = v[pos];
    v[pos]=0;
     int ss=*max_element(v.begin(),v.end());
	tree[treeNode].second = v[ss];
	//ye isliye kiya jisse tree[treenode].first ka data tree[treenode].second mei nahi aa jaye
	//hume max and second max daalne hien .first and .second mei. 
	return;

	
}

int main()
{
	int n, q;
	cin>>n;

	int* arr = new int[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}

	cin>>q;
	pair<int,int>* tree = new pair<int,int>[4*n];
	create(arr, tree, 0, n-1, 0);
	while(q--){
		char a;
		int b, c;
		cin>>a>>b>>c;

		if (a == 'Q')
		{
			pair<int,int> result = query(tree, 0, n-1, 0, b-1, c-1);
			cout << result.first+result.second << endl;
		}else{
			update(arr, tree, 0, n-1, 0, b-1, c);
		}

	}


	return 0 ; 



}