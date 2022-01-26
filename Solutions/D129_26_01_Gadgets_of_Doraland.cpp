// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    vector<int> TopK(vector<int>& array, int k)
    {
        // code here
        unordered_map<int,int> mp;
        for(int i: array)
            mp[i]++;
            
        vector<pair<int,int>> v;
        for(auto it: mp)
            v.push_back({it.second, it.first});
            
        sort(v.begin(), v.end());
        vector<int> ans;
        for(int i = v.size()-1;i>=0;i--)
        {
            ans.push_back(v[i].second);
            k--;
            if(!k)
                break;
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
        int n,k ;
        cin>>n;
        
        vector<int>array(n);
        
        for(int i=0; i<n; i++)
            cin>>array[i];
            
        cin>>k;
        
        Solution obj;
        vector<int> result = obj.TopK(array,k);
        
        for(int i=0; i<result.size();i++)
            cout<<result[i]<<" ";

        cout<<"\n";

    }
    return 0;
}  // } Driver Code Ends
