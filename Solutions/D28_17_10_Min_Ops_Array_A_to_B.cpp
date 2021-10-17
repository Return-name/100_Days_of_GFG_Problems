// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int lis(vector<int> const& a) {
        int n = a.size();
        const int INF = 1e9;
        vector<int> d(n+1, INF);
        d[0] = -INF;
    
        for (int i = 0; i < n; i++) {
            int j = upper_bound(d.begin(), d.end(), a[i]) - d.begin();
            if (d[j-1] < a[i] && a[i] < d[j])
                d[j] = a[i];
        }
    
        int ans = 0;
        for (int i = 0; i <= n; i++) {
            if (d[i] < INF)
                ans = i;
        }
        return ans;
    }
    
    int minInsAndDel(int A[], int B[], int N, int M) {
        // code here
        unordered_set<int> s;
        for(int i = 0;i<M;i++)
            s.insert(B[i]);
        vector<int> v;
        for(int i = 0;i<N;i++)
            if(s.find(A[i]) != s.end())
                v.push_back(A[i]);
        int a = lis(v);
        return N-a+M-a;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,M;
        cin>>N>>M;
        
        int A[N], B[M];
        for(int i=0; i<N; i++)
            cin>>A[i];
        for(int i=0; i<M; i++)
            cin>>B[i];

        Solution ob;
        cout << ob.minInsAndDel(A,B,N,M) << endl;
    }
    return 0;
}  // } Driver Code Ends
