// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&arr, int n)
    {   
        // Your code here
        set<pair<int,int>> s;
        s.insert({0, -1});
        int ans = 0;
        int cs = 0;
        for(int i = 0;i<n;i++)
        {
            cs += arr[i];
            auto it = s.lower_bound({cs, -2});
            if(it->first == cs)
            {
                ans = max(ans, i-it->second);
            }
            s.insert({cs, i});
        }
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
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}


  // } Driver Code Ends
