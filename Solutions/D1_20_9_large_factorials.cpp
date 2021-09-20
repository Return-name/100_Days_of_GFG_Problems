// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution {
public:
    vector<int> factorial(int N){
        // code here
        vector<int> v = {1,};
        int carry=0;
        for(int i = 2;i<=N;i++)
        {
            
            for(int j = 0;j<v.size();j++)
            {
                int pro = i * v[j];
                pro += carry;
                v[j] = pro - ((pro/10)*10);
                carry = (pro/10);
            }
            while(carry != 0)
            {
                v.push_back(carry - ((carry/10) * 10));
                carry = (carry/10);
            }
            //cout << "after i = " << i << "\n";
            /*
            for(auto k : v)
                cout << k << " ";
            cout << "\n";
            */
            
        }
        
        
        reverse(v.begin(), v.end());
        return v;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        vector<int> result = ob.factorial(N);
        for (int i = 0; i < result.size(); ++i){
            cout<< result[i];
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends
