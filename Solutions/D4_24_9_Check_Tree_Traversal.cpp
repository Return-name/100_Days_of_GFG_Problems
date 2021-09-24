// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends
//Back-end complete function Template for C++

struct Node
{
    int val;
    struct Node *left;
    struct Node *right;
    
    Node(int v)
    {
        val = v;
        left = right = NULL;
    }
};


Node* build_tree(int s, int e, int &prein, int pre[], unordered_map<int,int> &in_map, bool &not_poss)
{
    if(s > e)
    {
        //not_poss = false;
        return NULL;
    }
        
    int rootd = pre[prein];
    Node *root = new Node(rootd);
    prein++;
    
    if(in_map.find(rootd) == in_map.end())
    {
        not_poss = true;
        return root;
    }
    
    int inin = in_map[rootd];
    if(!(s <= inin && inin <= e))
    {
        not_poss = true;
        return root;
    }
    
    int ls = s,
        le = inin-1,
        rs = inin+1,
        re = e;
        
    root->left = build_tree(ls, le, prein, pre, in_map, not_poss);
    if(not_poss)
        return root;
        
    root->right = build_tree(rs, re, prein, pre, in_map, not_poss);
    
    return root;
}

int checkPost(Node* n, int post[], int &ind)
{
    if(n == NULL)
        return true;
        
    if(!checkPost(n->left, post, ind))
        return false;
    
    if(!checkPost(n->right, post, ind))
        return false;
    
    return (n->val == post[ind++]);
}

class Solution{
    public:
    bool checktree(int preorder[], int inorder[], int postorder[], int N) 
    { 
    	// Your code goes here
    	if(N == 0)
            return true;
            
        unordered_map<int, int> in_map;
        for(int i = 0;i<N;i++)
            in_map[inorder[i]] = i;
            
        int prein = 0;
    	
    	bool not_poss = false;
    	
    	Node *root = build_tree(0, N-1, prein, preorder, in_map, not_poss);
    	if(not_poss)
    	    return false;
    	    
    	int postin = 0;
    	
    	return checkPost(root, postorder, postin);
    } 

};


// { Driver Code Starts.

int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int preorder[n];
		int inorder[n];
		int postorder[n];

		for (int i = 0; i < n; ++i)
			cin>>preorder[i];

		for (int i = 0; i < n; ++i)
			cin>>inorder[i];

		for (int i = 0; i < n; ++i)
			cin>>postorder[i];
        
        Solution obj;
		if(obj.checktree(preorder, inorder, postorder, n))
			cout << "Yes\n";
		else
			cout<<"No\n";
	} 
	return 0; 
} 

  // } Driver Code Ends
