// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    string to_hex(int c)
    {
        stringstream ss;
        ss << hex << c;
        string res (ss.str());
        reverse(res.begin(), res.end());
        return res;
        
    }
  
    string encryptString(string arr) {
        // code here
        string ans = "";
        int c = 1;
        for(int i = 1;i<arr.size();i++)
        {
            if(arr[i] != arr[i-1])
            {
                ans += arr[i-1];
                ans += to_hex(c);
                c = 1;
            }
            else
                c++;
        }
        ans += arr.back();
        ans += to_hex(c);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    long long t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;

        Solution ob;
        cout<<ob.encryptString(S)<<endl;
    }
    return 0;
}  // } Driver Code Ends
