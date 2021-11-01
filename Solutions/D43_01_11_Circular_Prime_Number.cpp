// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;
class Solution{

 // } Driver Code Ends

	public:
	int isCircularPrime(int n) {
	    // Code here
	    //vector<bool> prime(100005, true);
	    if(n == 1)
	        return 0;
	    int len = to_string(n).size();
	    for(int i = 0;i<len;i++)
	    {
	        n = (n/10) + (n%10)*(pow(10,len-1));
	        for(int i = 2;i*i<=n;i++)
	            if(n % i == 0)
	                return 0;
	    }
	    
	    return 1;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans = ob.isCircularPrime(n);
		cout << ans <<"\n";
	}  
	return 0;
}  // } Driver Code Ends
