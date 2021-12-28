// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	void dfs(int v, vector<int> edges[], int c, int d, vector<bool> &vis)
	{
	    vis[v] = true;
	    for(int i: edges[v])
	    {
	        if((v == c && i == d) || (v == d && i == c))
	            continue;
	        if(!vis[i])
	            dfs(i, edges, c, d, vis);
	    }
	}
	
    //Function to find if the given edge is a bridge in graph.
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        // Code here
        vector<bool> vis(V, false);
        int c1=0, c2=0;
        for(int i = 0;i<V;i++)
            if(!vis[i])
            {
                c1++;
                dfs(i, adj, -1, -1, vis);
            }
        
        for(int i =0;i<V;i++)
            vis[i] = false;
            
        for(int i = 0;i<V;i++)
            if(!vis[i])
            {
                c2++;
                dfs(i, adj, c, d, vis);
            }
    
        return !(c1==c2);
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        int i=0;
        while (i++<E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back (v);
            adj[v].push_back (u);
        }
        
        int c,d;
        cin>>c>>d;
        
        Solution obj;
    	cout << obj.isBridge(V, adj, c, d) << "\n";
    }

    return 0;
}

  // } Driver Code Ends
