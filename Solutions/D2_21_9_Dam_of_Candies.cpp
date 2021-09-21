
/*
	Problem link - https://practice.geeksforgeeks.org/problems/10471201e923a0b88a0c1482e6c7e8cc6fdfe93a/1
*/

// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{
    
    public:
    int maxCandy(int height[], int n) 
    { 
        if(n == 1)
            return 0;
        
        // Your code goes here
        long long int l = 0;
        long long int r = n-1;
        
        long long int ans = -1; 
        long long int area;
        
        while(l < r)
        {
            area = min(height[l], height[r]) * (r-l-1);
            ans = max(ans, area);
            
            if(height[l] <= height[r])
                l++;
            else
                r--;
        }
        
        return ans;
        
    }   
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	int height[n];
    	for (int i = 0; i < n; ++i)
    	{
    		cin>>height[i];
    	}
    	
    	Solution obj;
    	
    	cout << obj.maxCandy(height,n)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
