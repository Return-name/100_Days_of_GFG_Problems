// { Driver Code Starts
// C++ program to find minimum swaps required
// to club all elements less than or equals
// to k together
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends


class Solution
{
public:
    int minSwap(int arr[], int n, int k) {
        // Complet the function
        vector<int> pos;
        for(int i = 0;i<n;i++)
            if(arr[i] <= k)
                pos.push_back(i);
        
        long long int ans = 1e18;
        for(int i = 0;i<=n-pos.size();i++)
        {
            auto it = lower_bound(pos.begin(), pos.end(), i);
            auto it2 = lower_bound(pos.begin(), pos.end(), i+pos.size()-1);
            long long int la = 0;
            if(it != pos.end() && *it == i)
                la += (it - pos.begin());
            else
                la += (it - pos.begin() );
            if(it2 != pos.end() && *it2 == i+pos.size()-1)
                la += (pos.end() - it2 - 1);
            else
                la += (pos.end() - it2);
            ans = min(ans, la);
        }
        return ans;
    }
};


// { Driver Code Starts.

// Driver code
int main() {

	int t,n,k;
	cin>>t;
	while(t--)
    {
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cin>>k;
        Solution ob;
        cout << ob.minSwap(arr, n, k) << "\n";
    }
	return 0;
}
  // } Driver Code Ends
