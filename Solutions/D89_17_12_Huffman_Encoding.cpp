// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
		vector<string> huffmanCodes(string S,vector<int> f,int N)
		{
		    // Code here
		    vector<string> build(string &S, vector<int> &f, int &N); 
		    return build(S, f, N);
		}
};

struct Node
{
    int f;
    Node *left, *right;
    
    Node(int fq)
    {
        f = fq;
        left = right = NULL;
    }
};

class Compare
{
    public:
    inline bool operator()(Node *a, Node *b)
    {
        return a->f > b->f;
    }
};

void dfs(Node *node, string cur, vector<string> &ans)
{
    if(!node->left && !node->right)
    {
        ans.push_back(cur);
        return ;
    }
    
    if(node->left)
        dfs(node->left, cur + '0', ans);
    if(node->right)
        dfs(node->right, cur + '1', ans);
}

vector<string> build(string &s, vector<int> &f, int &N)
{
    priority_queue<Node*, vector<Node*>, Compare> q;
    
    for(int i = 0;i<f.size();i++)
    {
        Node *p = new Node(f[i]);
        q.push(p);
    }
    
    Node *root;
    int tm = 0;
    while(!q.empty())
    {
        double lp, sp;
        int lc, sc;
        Node *ln, *sn;
        auto l = q.top();
        q.pop();
        auto r = q.top();
        q.pop();
        Node *p = new Node(l->f + r->f);
        p->left = l;
        p->right = r; 
        
        if(q.empty())
        {
            root = p;
            break;
        }
        q.push(p);
        tm++;
    }
    
    vector<string> ans;
    dfs(root, "", ans); 
    return ans;
}

// { Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
	    string S;
	    cin >> S;
	    int N = S.length();
	    vector<int> f(N);
	    for(int i=0;i<N;i++){
	        cin>>f[i];
	    }
	    Solution ob;
	    vector<string> ans = ob.huffmanCodes(S,f,N);
	    for(auto i: ans)
	    	cout << i << " ";
	    cout << "\n";
    }
	return 0;
}  // } Driver Code Ends
