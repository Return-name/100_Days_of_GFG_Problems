// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    pair<int,int> dfs(int i, int m, pair<int,int> e[], bool vis[])
    {
        vis[i] = true;
        if(e[i].first == -1)
        {
            return {i, m};       
        }
        auto v = e[i];
        m = min(m, v.second);
        if(!vis[v.first])
            return dfs(v.first, m, e, vis);
    }
    
    vector<vector<int>> solve(int n,int p,vector<int> a,vector<int> b,vector<int> d)
    {
        // code here
        pair<int,int> edges[n+1];
        bool f[n+1];
        bool vis[n+1] = {false};
        
        fill(f, f+n+1 ,true);
        fill(edges, edges+n+1, make_pair(-1,-1));

        for(int i = 0;i<p;i++)
        {
            edges[a[i]] = {b[i], d[i]};
            f[b[i]] = false;
        }
        
        vector<vector<int>> ans;
        
        for(int i = 1;i<=n;i++)
        {
            if(!vis[i] && f[i])
            {
                pair<int,int> la = dfs(i, 1e9, edges, vis);
                if(la.second != 1e9)
                    ans.push_back({i, la.first, la.second});
            }
        }
        return ans;
    }
};


// { Driver Code Starts.
int main()
{
	int t,n,p;
	cin>>t;
	while(t--)
    {
        cin>>n>>p;
        vector<int> a(p),b(p),d(p);
        for(int i=0;i<p;i++){
            cin>>a[i]>>b[i]>>d[i];
        }
        Solution obj;
        vector<vector<int>> answer = obj.solve(n,p,a,b,d);
        cout<<answer.size()<<endl;
        for(auto i:answer)
        {
            cout<<i[0]<<" "<<i[1]<<" "<<i[2]<<endl;
        }
        
    }
	return 0;
}  // } Driver Code Ends
