// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int editDistance(string s, string t) {
        // Code here
        int dp[s.size()+1][t.size()+1];
        for(int i = 0;i<s.size()+1;i++)
            for(int j = 0;j<t.size()+1;j++)
                dp[i][j] = 1e9;
        dp[0][0] = 0;
        for(int i = 0;i<s.size()+1;i++)
        {
            for(int j = 0;j<t.size()+1;j++)
            {
                if(dp[i][j] != 1e9)
                {
                    if(i != s.size())
                        dp[i+1][j] = min(dp[i+1][j], dp[i][j]+1);
                    if(j != t.size())
                        dp[i][j+1] = min(dp[i][j+1], dp[i][j]+1);
                    if(i != s.size() && j != t.size())
                        dp[i+1][j+1] = (s[i] == t[j]) ? min(dp[i+1][j+1], dp[i][j]) : min(dp[i+1][j+1], dp[i][j]+1);
                    
                }
            }
        }
        return dp[s.size()][t.size()];
    }
};

// { Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends
