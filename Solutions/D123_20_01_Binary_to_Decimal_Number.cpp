// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
		int binary_to_decimal(string str)
		{
		    // Code here.
		    int ans = 0;
		    int i = str.size()-1, j=0;
		    while(i >= 0)
		    {
		        if(str[i] == '1')
		            ans += 1<<(j);
		        i--;
		        j++;
		    }
		    return ans;
		}
};

// { Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	string str;
    	cin >> str;
    	Solution ob;
    	int  ans = ob.binary_to_decimal(str);
    	cout << ans <<"\n";
    }
	return 0;
}  // } Driver Code Ends
