// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:
	int search(string pat, string txt) {
	    // code here
	    int arr[2][26];
	    for(int i = 0;i<26;i++)
	        arr[0][i] = arr[1][i] = 0;
	        
	    for(char c : pat)
	    {
	        arr[0][c - 'a']++;
	    }
	    
	    int cl = 0;
	    int n = pat.size();
	    
	    int ans = 0;
	    for(int i = 0;i<txt.size();i++)
	    {
	        char c = txt[i];
	        arr[1][c - 'a']++;
	        cl++;
	        if(cl > n)
	        {
	            arr[1][txt[i-cl+1] - 'a']--;
	            cl--;
	        }
	        int flag = 1;
	        for(int j = 0;j<26;j++)
	        {
	            if(arr[0][j] != arr[1][j])
	            {
	                flag = 0;
	                break;
	            }
	        }
	        if(flag)
	            ans++;
	        
	    }
	    return ans;
	    
	}

};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends
