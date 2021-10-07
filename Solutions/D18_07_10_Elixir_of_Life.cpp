// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    vector<int> z_function(string s) {
        int n = (int) s.length();
        vector<int> z(n);
        for (int i = 1, l = 0, r = 0; i < n; ++i) {
            if (i <= r)
                z[i] = min (r - i + 1, z[i - l]);
            while (i + z[i] < n && s[z[i]] == s[i + z[i]])
                ++z[i];
            if (i + z[i] - 1 > r)
                l = i, r = i + z[i] - 1;
        }
        return z;
    }
    
    int occ(int i, int l, string s)
    {
    	string s2 = s.substr(i, l) + '$' + s;
    	vector<int> z = z_function(s2);
    	int ans = 0;
    	for(int i = 0;i<s.size();i++)
    		if(z[i+l+1] == l)
    			ans++;
    	return ans;
    }
    
    int maxFrequency(string s)
    {
    	// code here
        vector<int> z = z_function(s);
    	int l = 1;
    	for(int i = s.size()-1;i>=0;i--)
    	{
    		if(z[i] == l)
    		{
    			return occ(i, l, s);
    		}
    		l++;
    	}
    	return 1;
    	
    }
};

// { Driver Code Starts.

int main() 
{
   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string str;
   		cin >> str;
   		Solution obj;
   		cout << obj.maxFrequency(str) << "\n";
   	}
    return 0;
}  // } Driver Code Ends
