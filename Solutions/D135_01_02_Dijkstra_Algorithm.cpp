// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> e[], int S)
    {
        // Code here
       
        #define ll long long int
         const ll inf = 1e18;
        int n = V;
        vector<ll> dis(n, inf);
		dis[S] = 0;	
		multiset<pair<ll, ll>> s;
		for(ll i = 0;i<n;i++)
			if(i == S)
			    s.insert({0ll, i});
			else
			    s.insert({inf, i});
		//s.insert({0ll, S});
		while(s.size() > 0)
		{
			auto p = s.begin();
			ll d = p->first;
			ll v = p->second;
			s.erase(p);
			for(auto c : e[v])
			{   
				if(dis[c[0]] > d + c[1])
				{
					s.erase(s.find({dis[c[0]], c[0]}));
					dis[c[0]] = d + c[1];
					s.insert({dis[c[0]], c[0]});
				}
			}
			//s.erase(p);
		}
		vector<int> ans;
		for(ll i : dis)
			ans.push_back(i);
		return ans;
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
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}

  // } Driver Code Ends
