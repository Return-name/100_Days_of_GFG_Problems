// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    void clonestack(stack<int> st, stack<int>& cloned)
    {
        //code here
        int n = st.size();
        for(int i = 0;i<n;i++)
        {
            int t = st.top();
            st.pop();
            for(int j = 0;j<i;j++)
            {
                st.push(cloned.top());
                cloned.pop();
            }
            cloned.push(t);
            for(int j = 0;j<i;j++)
            {
                cloned.push(st.top());
                st.pop();
            }
        }
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
        int arr[N];
        stack<int> st;
        vector<int> copy;
        for(int i = 0; i < N; i++){
            cin >> arr[i];
            st.push(arr[i]);
            copy.push_back(arr[i]);
        }
        
        reverse(copy.begin(), copy.end());
        
        Solution ob;
        stack<int> cloned;
        ob.clonestack(st,cloned);
        vector<int> check;
        while(cloned.size())
        {
            check.push_back(cloned.top());
            cloned.pop();
        }
        
        int flag = 0;
        if(check!=copy)
            flag = 1;
        
        cout<<1-flag<<endl;
    }
    return 0; 
} 
  // } Driver Code Ends
