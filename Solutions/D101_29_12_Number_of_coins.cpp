// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	int ans(int V, int coins[], int &M, vector<int> &dp)
	{
	    if(V < 0)
	        return 1e9;
	    if(dp[V] == -1)
	        return 1e9;
	    if(dp[V] < 1e9)
	        return dp[V];
	       
	    int lans = 1e9;
	    for(int i =0;i<M;i++)
	    {
	        int t = ans(V-coins[i], coins, M, dp);
	        if(t == 1e9)
	            continue;
	       lans = min(lans, t);
	        
	    }
	    if(lans != 1e9)
	        return dp[V] = lans + 1;
	    else
	        dp[V] = -1;
	   return 1e9;
	}
	
	int minCoins(int coins[], int M, int V) 
	{ 
	    // Your code goes here
	    sort(coins, coins+M);
	    vector<int> dp(V+1, 1e9);
	    dp[0] = 0;
	    
	    ans(V, coins, M, dp);
	    return dp[V];
	} 
	  
};

// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends
