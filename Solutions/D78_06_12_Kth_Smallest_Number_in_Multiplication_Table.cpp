// { Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    int KthSmallest(int m, int n, int k) {
        //Write your code here
        long long int l = 1, r = m*n, mid;
        while(l <= r)
        {
            mid = (l+r)/2;
            long long int small=0, eq=0;
            for(int i  = 1;i<=m;i++)
            {
                small += min((mid-1)/i, (long long int)n);
                eq += (min((mid/i), (long long )n)*i) == mid ? 1 : 0;
            }
            if(k > small && k-small <= eq)
                break;
            else if(k <= small)
                r = mid-1;
            else
                l = mid+1;
        }
        return mid;
        
    }
};


// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int m, n, k;
	    cin >> m >> n >> k;
	    Solution ob;
	    int ans = ob.KthSmallest(m, n, k);
	    cout << ans << endl;
	}
	return 0;
}
  // } Driver Code Ends
