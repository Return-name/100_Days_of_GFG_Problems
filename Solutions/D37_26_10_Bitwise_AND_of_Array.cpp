// { Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    int count(int N, vector<int> A,int X)
    {
        // code here
        int ans = N;
        int d = 0;
        for(int i = 30;i>=0;i--)
        {
            if(((X>>i) & 1) == 1)
            {
                d ^= (1<<i);
                continue;
            }
            
            int lans = 0;
            int p = d^(1<<i);
            for(int j = 0;j<N;j++)
            {
                if((A[j]&p) == p)
                lans++;
            }
            ans = min(ans, N-lans);
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int N,X;
        cin>>N>>X;
        vector<int> A(N);
        for(auto &i:A)
            cin>>i;
        Solution obj;
        int ans = obj.count(N, A, X);
        cout<<ans<<endl;
    }
}  // } Driver Code Ends
