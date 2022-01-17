// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++

class Solution{   
  public:
    bool check_pal(string s)
    {
        for(int i = 0, j = s.size()-1;i<j;i++, j--)
        {
            if(s[i] != s[j])
                return false;
        }
        return true;
    }
  
    // Function to check if a palindrome pair exists
    bool palindromepair(int N, string arr[]) {
        // code here
        map<char, vector<int>> mp;
        for(int i = 0;i<N;i++)
            mp[arr[i].back()].push_back(i);
            
        for(int i = 0;i<N;i++)
        {
            for(auto j : mp[arr[i][0]])
            {
                if(i == j)
                    continue;
                    
                if(check_pal(arr[i] + arr[j]))
                    return true;
            }
        }
        
        return false;
    }

};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        string arr[N];
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.palindromepair(N, arr) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends
