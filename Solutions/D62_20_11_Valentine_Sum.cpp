// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


 // } Driver Code Ends
/*
// node structure:

struct Node
{
    int data;
    Node* left;
    Node* right;
};

*/
int inf = 1e9;
void dfs(Node *n, int &ans, int p, int k)
{
    if(p <= k)
        ans += n->data;
    else
        return;
    if(n->left)
        dfs(n->left, ans, p+1, k);
    if(n->right)
        dfs(n->right, ans, p+1, k);
}

int func(Node *n, int t, int k, int &ans)
{
    if(n->data == t)
    {
        dfs(n, ans, 0, k);
        return 1;
    }
    if(n->left)
    {
        int r = func(n->left, t, k, ans);
        if(r <= k)
        {
            ans += n->data;
            if(n->right)
                dfs(n->right, ans, r+1, k);
            return r+1;
        }
    }
    if(n->right)
    {
        int r = func(n->right, t, k, ans);
        if(r <= k)
        {
            ans += n->data;
            if(n->left)
                dfs(n->left, ans, r+1, k);
            return r+1;
        }
    }
    return inf;
}

class Solution{

    public:
    int sum_at_distK(Node* root, int t, int k)
    {
        // Your code goes here
        int ans = 0;
        func(root, t, k, ans);
        return ans;
    }


};


// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    getchar();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        
        int target,k;
        cin>> target >> k;
        getchar();
        Solution obj;
        cout<< obj.sum_at_distK(root,target,k) << endl;
    }
	return 0;
}

  // } Driver Code Ends
