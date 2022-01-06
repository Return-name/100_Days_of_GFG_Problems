// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    
    string longestCommonPrefix (string arr[], int N)
    {
        // your code here
        int n = 1e9;
        for(int i = 0;i<N;i++)
            n = min(n, (int)arr[i].size());
        string ans = "";
        for(int i = 0;i<n;i++)
        {
            int j = ans.size();
            for(int k = 1;k<N;k++)
                if(arr[k][j] != arr[k-1][j])
                    return (ans.size() == 0 ? "-1": ans);
            ans += arr[0][j];
        }
        if(ans.size() == 0)
            return "-1";
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        
        Solution ob;
        cout << ob.longestCommonPrefix (arr, n) << endl;
    }
}

// Contributed By: Pranay Bansal
  // } Driver Code Ends
