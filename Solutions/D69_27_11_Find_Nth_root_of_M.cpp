// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	int NthRoot(int n, int m)
	{
	    // Code here.
	    long long int l = 1;
	    long long int r = m;
	    long long int mid;
	    while(l<=r)
	    {
	        
	        mid = (l+r)/2;
	        long long int  c = 1;
	        int cont = 0;
	        for(int j = 0;j<n;j++)
	       {
	           c *= mid;
	           if(c > INT_MAX)
	           {
	               r = mid-1;
	               cont = true;
	               break;
	           }
	       }
	       if(cont)
	        continue;
	        
	        if(c == m)
	            break;
	        else if (c < m)
	            l = mid+1;
	       else
	            r = mid-1;
	    }
	    if((int)pow(mid, n) == m)
	        return mid;
	   else 
	    return -1;
	}  
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		Solution ob;
		int ans = ob.NthRoot(n, m);
		cout << ans << "\n";
	}  
	return 0;
}  // } Driver Code Ends
