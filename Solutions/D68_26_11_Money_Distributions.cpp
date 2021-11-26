// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	int m = 1e9+7;
	
	public:
	long modPow(long a, long x, long p) {
        //calculates a^x mod p in logarithmic time.
        long res = 1;
        while(x > 0) {
            if( x % 2 != 0) {
                res = (res * a) % p;
            }
            a = (a * a) % p;
            x /= 2;
        }
        return res;
    }
    
    long modInverse(long a, long p) {
        //calculates the modular multiplicative of a mod m.
        //(assuming p is prime).
        return modPow(a, p-2, p);
    }
    long modBinomial(long n, long k, long p) {
    // calculates C(n,k) mod p (assuming p is prime).
    
        long numerator = 1; // n * (n-1) * ... * (n-k+1)
        for (int i=0; i<k; i++) {
            numerator = (numerator * (n-i) ) % p;
        }
    
        long denominator = 1; // k!
        for (int i=1; i<=k; i++) {
            denominator = (denominator * i) % p;
        }
    
        // numerator / denominator mod p.
        return ( numerator* modInverse(denominator,p) ) % p;
    }
    
    int totalWays(int N, int K) {
        long long int ans = modBinomial(N-1, K-1, m); 
        return ans;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n , k;
		cin >> n >> k;
		Solution ob;
		int ans = ob.totalWays(n, k);
		cout << ans << "\n";
	}  
	return 0;
}  // } Driver Code Ends
