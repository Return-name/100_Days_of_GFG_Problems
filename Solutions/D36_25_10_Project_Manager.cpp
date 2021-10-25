// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'


 // } Driver Code Ends
class Solution{
    public:
    int minTime(vector<pair<int, int>> &dep, int dur[], int n, int m) {
        // 	Write your code here
        vector<int> in(n, 0), t, dp(n, 0);
        vector<int> edges[n];
        for(int i = 0;i<m;i++)
        {
            in[dep[i].second]++;
            edges[dep[i].first].push_back(dep[i].second);
        }
        
        queue<int> q;
        for(int i = 0;i<n;i++)
        {
            if(in[i] == 0)
            {
                q.push(i);
                dp[i] = dur[i];
            }
        }
        
        while(!q.empty())
        {
            auto c = q.front();
            q.pop();
            
            t.push_back(c);
            for(auto v: edges[c])
            {
                dp[v] = max(dp[v], dur[v] + dp[c]);
                
                in[v]--;
                if(in[v] == 0)
                    q.push(v);
            }
        }
        
        if(t.size() != n)
            return -1;
        
        int ans = 0;
        for(int i : dp)
        {
            ans = max(ans, i);
        }
        return ans;
    }
};


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, x, y;
        cin >> n >> m;
        int duration[n + 5];
        vector<pair<int, int>> dependency;
        for (int i = 0; i < n; i++) cin >> duration[i];
        for (int i = 0; i < m; i++) {
            cin >> x >> y;
            dependency.push_back({x, y});
        }
        Solution obj;
        cout << obj.minTime(dependency, duration, n, m) << endl;
    }
    return 0;
}  // } Driver Code Ends
