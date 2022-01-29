// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string s) 
    { 
        // code here 
        vector<string> v;
        string t = "";
        for(char c: s)
        {
            if(c == '.')
                v.push_back(t), t = "";
            else
                t += c;
        }
        if(t.size() > 0)
            v.push_back(t);
        if(v.size() == 0)
            return "";
        string ans = v[v.size()-1];
        for(int i = v.size()-2;i>=0;i--)
            ans += "." + v[i];
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
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}  // } Driver Code Ends