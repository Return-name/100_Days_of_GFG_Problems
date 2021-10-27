// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
    public:
    string convert(string s, int n) {
        //code
        if(n == 1)
            return s;
        vector<string> v(n, "");
        int d = 0, dir = 0;
        for(int i = 0;i<s.size();i++)
        {
            v[d] += s[i];
            if(d == n-1)
                dir = 0;
            if(d == 0)
                dir = 1;
            dir ? d++ : d--;     
        }
        string ans = "";
        for(int i = 0;i<n;i++)
            ans += v[i];
        return ans;
    }
};

// { Driver Code Starts.
// Driver program
int main()
{
    int t;
    cin>>t;
    while (t--){
        string str;
        cin>>str;
        int n;
        cin>>n;
        Solution ob;
        cout<<ob.convert(str, n)<<endl;
    }
    return 0;
}  // } Driver Code Ends
