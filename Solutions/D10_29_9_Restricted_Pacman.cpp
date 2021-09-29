// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h> 
#include <unordered_set>
using namespace std; 

 // } Driver Code Ends
//User function Template for C++


class Solution{
    public:
    int candies(int m, int n) 
    { 
    	// Your code goes here
    	
    	if(m > n)
		swap(m,n);

	vector<int> v(1000000, 0);
	v[0] = 1;
	int ans = 0;
	for(int i = 0;i<v.size();i++)
	{
		if(v[i] == 1)
		{
			int l = 0;
			for(int j = i;v[j] && j < v.size();j++,l++);
			if(l == m)
				break;
			
			v[i+m] = 1;
			v[i+n] = 1;
		
		}
		else
			ans++;	
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
		int m,n;
		cin>>m>>n;
		Solution obj;
		cout << obj.candies(m,n)<<endl; 
	}
	return 0; 
} 



  // } Driver Code Ends
