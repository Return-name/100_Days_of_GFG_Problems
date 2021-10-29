// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	int find_min(int a[], int n, int k) {
        // Your code geos here
        int e = 0, o=0;
        for(int i = 0;i<n;i++)
        {
            e += (a[i]+1)/2-1;
            if(a[i]%2 == 0)
                o++;
        }
        
        if(e+o < k)
        {
            return -1;        
        }
        else
            return n + 2*k - max(1, k-e);
    }

};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        cin >> k;
        Solution obj;
        cout << obj.find_min(a, n, k) << endl;
    }
    return 1;
}
  // } Driver Code Ends
