// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    void cal(int p, int N, int l, int n, vector<int> &ans)
    {
        if(p == N)
        {
            ans.push_back(n);
            return;
        }
        for(int i = l+1;i<=9;i++)
        {
            cal(p+1, N, i, n*10+i, ans);
        }
        return;
    }

    vector<int> increasingNumbers(int N)
    {
        // Write Your Code here
        vector<int> ans;
        if(N == 1)
            ans.push_back(0);
        cal(0, N, 0, 0, ans);
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
        int N;
        cin>>N;
        Solution ob;
        vector<int> ans = ob.increasingNumbers(N);
        for(auto num : ans){
            cout<< num <<" ";
        }
        cout<<endl;
        
    }
    return 0;
}  // } Driver Code Ends
