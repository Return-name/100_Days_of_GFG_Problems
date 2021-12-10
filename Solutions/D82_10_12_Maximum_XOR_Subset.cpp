// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	void insert(int m, int b[])
	{
	    for(int i = 19;i>=0;i--)
	    {
	        if((m & 1 << i) == 0)
	            continue;
	        if(!b[i])
	        {
	            b[i] = m;
	            return;
	        }
	        
	        m ^= b[i];
	    }
	}
	
	int maxXor(int arr[], int n)
	{
		// Your code goes here
		int b[20];
	    for(int i = 0;i<20;i++)
	        b[i] = 0;
		for(int i = 0;i<n;i++)
		    insert(arr[i], b);
        
        int ans = 0;
        for(int i = 19;i>=0;i--)
        {
            if(!b[i])
                continue;
            
            if(ans & 1 << i)
                continue;
            ans ^= b[i];
        }
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
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

	   

	    Solution ob;
	    cout << ob.maxXor(a, n) << "\n";
   
    }
    return 0;
}
  // } Driver Code Ends
