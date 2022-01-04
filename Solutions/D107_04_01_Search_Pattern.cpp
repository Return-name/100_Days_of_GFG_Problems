// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
        vector<int> z_function(string s) {
            int n = (int) s.length();
            vector<int> z(n);
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
    
        vector <int> search(string pat, string txt)
        {
            //code hee.
            string s = pat + "#" + txt;
            vector<int> z = z_function(s);
            vector<int> ans;
            for(int i = pat.size()+1;i<s.size();i++)
                if(z[i] == pat.size())
                    ans.push_back(i - pat.size());
            return ans;
        }
     
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        if(res.size()==0)
            cout<<"-1 ";
        else
            for (int i : res)
                cout << i << " ";
        cout << endl;
    }
    return 0;
}

  // } Driver Code Ends
