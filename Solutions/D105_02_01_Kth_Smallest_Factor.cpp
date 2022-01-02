// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int kThSmallestFactor(int N , int K) {
        // code here
        vector<int> v1, v2;
        for(int i = 1;i*i<=N;i++)
        {
            if(N%i == 0)
            {
                v1.push_back(i);
                if(i*i != N)
                {
                    v2.push_back(N/i);
                }
            }
        }
        for(int i = v2.size()-1;i>=0;i--)
            v1.push_back(v2[i]);
        if(K <= v1.size())
            return v1[K-1];
        else
            return -1;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,K;
        
        cin>>N>>K;

        Solution ob;
        cout << ob.kThSmallestFactor(N,K) << endl;
    }
    return 0;
}  // } Driver Code Ends
