// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    long long countSubarray(int N,vector<int> A,long long L,long long R) {
        // code here 
        long long int c = 0;
        long long int ans = 0;
        long long int i = 0, j = 0;
        while(j < N)
        {
            c += A[j];
            while(i <= j && c > R)
                c -= A[i], i++;
            ans += j-i+1;
            j++;
        }
        i = 0;
        j = 0;
        c = 0;
        while(j < N)
        {
            c += A[j];
            while(i <= j && c >= L)
                c -= A[i], i++;
            ans -= j-i+1;
            j++;
        }
        
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        long long L,R;
        cin>>N>>L>>R;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        Solution obj;
        auto ans = obj.countSubarray(N,A,L,R);
        cout<<ans<<endl;
    }
}    // } Driver Code Ends
