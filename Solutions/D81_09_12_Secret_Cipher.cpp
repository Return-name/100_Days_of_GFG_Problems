// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

// return a string formed by compressing string s
// do not print anything

class Solution{
    public:
    vector<int> z_function(string s) {
        int n = (int) s.length();
        vector<int> z(n,0);
        for (int i = 1, l = 0, r = 0; i < n; ++i) {
            if (i <= r)
                z[i] = min (r - i + 1, z[i - l]);
            while (i + z[i] < n && s[z[i]] == s[i + z[i]])
                ++z[i];
            if (i + z[i] - 1 > r)
                l = i, r = i + z[i] - 1;
        }
        return z;
    }
    
    
    string compress(string s)
    {
        // Your code goes here
        vector<int> z = z_function(s);
        string ans = "";
        int n = s.size();
        int l = 1e9;
        for(int i = n-1;i>=0;i--)
        {
            if(i == 0)
            {
                ans.push_back(s[i]);
                break;
            }
            if(z[i] >= i && 2*i <= l)
            {
                for(int j = 0;j<i-1;j++)
                    ans.pop_back();
                ans.push_back('*');
                l = i;
            }
            else
                ans.push_back(s[i]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution obj;
        cout<< obj.compress(s) << "\n";
    }
    return 0;
}
  // } Driver Code Ends
