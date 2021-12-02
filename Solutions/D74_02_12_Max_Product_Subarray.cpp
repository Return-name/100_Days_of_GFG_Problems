// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(vector<int> arr, int n) {
	    // code here
	    long long int ans = arr[0], p= arr[0];
	    long long int l = arr[0];
	    //int r = 0;
	    for(int i =1 ;i<n;i++)
	    {
	        if(p == 0)
	            p = 1;
	           if(l == 0)
	            l = 1;
	        if(arr[i] == 0)
	        {
	            p = 1;
	            l = 1;
	        }
	        else if(arr[i] > 0)
	       {
	           p *= arr[i];
	       }
	       else
	       {
	           if(p < 0)
	               ;//l = 1;
	           else if (l >= 1)
	                l = p * arr[i];
	           p *= arr[i];
	           
	           //l = p;
	       }
	       ans = max(ans, p);
	       if(l != 0)
	       ans = max(ans, p/l);
	    }
	    return ans;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends
