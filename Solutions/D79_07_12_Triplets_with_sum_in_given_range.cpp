// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countTriplets(int Arr[], int N, int L, int R) {
        // code here
        sort(Arr, Arr+N);
        long long int ans = 0;
        for(int i = 0;i<N;i++)
        {
            for(int j = i+1;j<N;j++)
            {
                long long int sum = Arr[i] + Arr[j];
                auto it1 = upper_bound(Arr+j+1, Arr+N, R - sum);
                auto it2 = lower_bound(Arr+j+1, Arr+N, L - sum);
                ans += max(0l, it1-it2);
            }
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
        cin >> N;
        int Arr[N];
        for (int i = 0; i < N; i++) cin >> Arr[i];
        int L, R;
        cin >> L >> R;
        Solution obj;
        cout << obj.countTriplets(Arr, N, L, R) << endl;
    }
    return 0;
}  // } Driver Code Ends
