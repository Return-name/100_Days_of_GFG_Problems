// { Driver Code Starts
// C++ program to find all distinct palindrome sub-strings
// of a given string
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
  public:
    int palindromeSubStrs(string s) {
        // code here
        int n = s.size();
        
        vector<vector<bool>> dp(n, vector<bool> (n, false));
        
        for(int k = 1;k<=n;k++)
        {
            for(int i = 0, j = i + k -1 ;j<n;i++, j++)
            {
                if(k == 1)
                    dp[i][j] = true;
                else if(k == 2)
                    dp[i][j] = (s[i] == s[j]);
                else
                    dp[i][j] = (s[i] == s[j] && dp[i+1][j-1]);
            }
        }
        
        unordered_set<string> us;
        
        for(int i = 0;i<n;i++)
            for(int j = i;j<n;j++)
                if(dp[i][j])
                    us.insert(s.substr(i, (j-i+1)));
                    
        return us.size();
    }
};

// { Driver Code Starts.

// Driver program
int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        cout << ob.palindromeSubStrs(str) << endl;
    }
    return 0;
}
  // } Driver Code Ends
