// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
  public:
    string arrangeString(string str)
    {
        //code here.
        string ans = "";
        int s = 0;
        for(char c: str)
        {
            if(c >= '0' && c <= '9')
            {
                s += c - '0';
            }
            else
                ans += c;
        }
        sort(ans.begin(), ans.end());
        ans += to_string(s);
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution ob;
        cout <<ob.arrangeString(s) << endl;
    }
return 0;
}

  // } Driver Code Ends
