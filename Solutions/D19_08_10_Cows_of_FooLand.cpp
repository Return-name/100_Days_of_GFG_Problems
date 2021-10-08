// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	const int MOD = 1e9+7;
	
    vector<vector<long long int>> matMul(vector<vector<long long int>> &a, vector<vector<long long int>> &b)
	{
	    //long long int ans[2][2];
	    vector<vector<long long int>> ans(2, vector<long long int>(2));
	    int i, j, k;
	    for(int i = 0;i<2;i++)
	        for(int j = 0;j<2;j++)
	            for(ans[i][j] = k = 0;k<2;k++)
	            {
	                ans[i][j] += ((a[i][k]%MOD) * (b[k][j]%MOD))%MOD;
                    ans[i][j] %= MOD;
	            }
	    return ans;
	}
	
	int TotalAnimal(long long int N){
	    // Code here
	    vector<vector<long long int>> base = { {1, 1}, {1, 0}};
	    long long int p = ++N;
	    vector<vector<long long int>> ans(2, vector<long long int>(2));
	    int i, j;
	    for(i = 0;i<2;i++)
	        for(j = 0;j<2;j++)
	            ans[i][j] = (i == j);
	    while(p)
	    {
	        if (p & 1)
	            ans = matMul(ans, base);
	        base = matMul(base, base);
	        p >>= 1;    
	    }
	    return ans[0][1];
	    
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		long long int N;
		cin >> N;
		Solution ob;
		int ans = ob.TotalAnimal(N);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends
