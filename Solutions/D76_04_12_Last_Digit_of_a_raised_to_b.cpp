// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int getLastDigit(string a, string b) {
        // code here
        if(b == "0")
            return 1;
        int l = a[a.size()-1] - 48;
        int cycle[10][4] = {
            0, 0, 0, 0,
            1, 1, 1, 1,
            2, 4, 8, 6,
            3, 9, 7, 1,
            4, 6, 4, 6,
            5, 5, 5, 5,
            6, 6, 6, 6,
            7, 9, 3, 1,
            8, 4, 2, 6,
            9, 1, 9, 1
        };
        
        int pos = 0;
        if(b.size() > 1)
            pos = stoi(b.substr(b.size()-2)) % 4;
        else
            pos = stoi(b) % 4;
        if(pos == 0)
            pos = 4;
        return cycle[l][pos-1];
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string a,b;
        
        cin>>a>>b;

        Solution ob;
        cout << ob.getLastDigit(a,b) << endl;
    }
    return 0;
}  // } Driver Code Ends
