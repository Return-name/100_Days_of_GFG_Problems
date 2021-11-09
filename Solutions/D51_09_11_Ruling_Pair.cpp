// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++

//Back-end complete function Template for C++

class Solution{
    
    public:
    int RulingPair(vector<int> arr, int n) 
    { 
    	// Your code goes here
    	vector<pair<int,int>> v;
    	for(int i = 0;i<arr.size();i++)
    	{
    	    int a = 0;
    	    int s = arr[i];
    	    while(s > 0)
    	    {
    	        a += s%10;
    	        s /= 10;
    	    }
    	    v.push_back({a, arr[i]});
    	}
    	sort(v.begin(), v.end());
    	int ans = -1;
    	for(int i = n-1;i>=1;i--)
    	{
    	    if(v[i].first == v[i-1].first)
    	        ans = max(ans, v[i].second+v[i-1].second);
    	}
    	return ans;
    }   
};


// { Driver Code Starts.

int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<int> arr(n);
		for (int i = 0; i < n; ++i)
			cin>>arr[i];
	    Solution obj;
		cout << obj.RulingPair(arr,n)<<"\n";
	}
	return 0; 
} 

  // } Driver Code Ends
