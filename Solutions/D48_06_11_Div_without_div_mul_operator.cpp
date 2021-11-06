// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    long long divide(long long a, long long b) 
    {
        //code here
        int sign = 1;
        if(a < 0 && b > 0)
            a = -a, sign = -1;
        else if(a > 0 && b < 0)
            b = -b, sign = -1;
        else if(a < 0 && b < 0)
            a = -a, b=-b;
        
        vector<pair<long long int, int>> v;
        v.push_back({b, 1});
        
        long long int s = b;
        int p = 1;
        for(int i = 1;i<60;i++)
        {
            v.push_back({s+s, p+p});
            s += s;
            p += p;
            if(s > 1e15)
                break;
        }
        
        long long int ans = 0;
        for(int i = v.size();i>=0;i--)
        {
            if(v[i].first <= a)
            {
                ans += v[i].second;
                a -= v[i].first;
            }
        }
        if(sign < 0)
            ans = -ans;
        return ans;
        
    }
};

// { Driver Code Starts.
int main() {
	int t;
	cin >> t;

	while (t--)
	{

		long long a, b;
		cin >> a >> b;
		
		Solution ob;
		cout << ob.divide(a, b) << "\n";
	}

	return 0;
}
  // } Driver Code Ends
