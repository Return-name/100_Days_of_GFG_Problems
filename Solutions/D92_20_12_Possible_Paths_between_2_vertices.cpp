// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution {
  public:
    int dfs(int v, int d, vector<int> adj[], vector<int> &done, int &ans)
    {
        if(v == d)
        {
            ans++;
            return 1;
        }
        
        int lans = 0;
        for(int u: adj[v])
            if(done[u] == -1)
                lans += dfs(u, d, adj, done, ans);
            else
            {
                lans += done[u];
                ans += done[u];
            }
            
        done[v] = lans;
    }
  
    // Function to count paths between two vertices in a directed graph.
    int countPaths(int V, vector<int> adj[], int s, int d) {
        // Code here
        vector<int> done(V, -1);
        done[d] = 1;
        
        int ans = 0;
        
        dfs(s, d, adj, done, ans);
                
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // adj[v].push_back(u);
        }
        int source, destination;
        cin >> source >> destination;
        Solution obj;
        cout << obj.countPaths(V, adj, source, destination) << endl;
    }
    return 0;
}  // } Driver Code Ends
