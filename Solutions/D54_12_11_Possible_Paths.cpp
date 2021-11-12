// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution {
  public:
	int mod = 1e9+7;
	int dfs(int u, int v, int k, vector<vector<int>> &g, int dp[55][55])
	{
	    if(k < 0)
	        return 0;
	   if(k == 0 && u == v)
	        return 1;
	        
	    if(dp[u][k] != -1)
	        return dp[u][k];
	        
	   int ans = 0;
	   for(int j = 0;j<g[u].size();j++)
	   {
	       if(g[u][j] == 0)
	            continue;
	       ans = (ans + dfs(j, v, k-1, g, dp)) % mod;
	   }
	   return dp[u][k] = ans;
	}
	
	int MinimumWalk(vector<vector<int>>&graph, int u, int v, int k){
	    // Code here
	    int dp[55][55];
	    long long int ans = 0;
	    for(int i = 0;i<55;i++)
	        for(int j = 0;j<55;j++)
	            dp[i][j] = -1;
	    return dfs(u, v, k,graph, dp);   
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>graph(n, vector<int>(n,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> graph[i][j];
			}
		}
		int u, v, k;
		cin >> u >> v >> k;
		Solution obj;
		int ans = obj.MinimumWalk(graph, u, v, k);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends
