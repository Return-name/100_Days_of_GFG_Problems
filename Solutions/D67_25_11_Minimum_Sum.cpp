// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    string solve(int arr[], int n) {
        // code here
        sort(arr, arr+n);
        string a="", b="";
        for(int i = 0;i<n;i+=2)
            a.push_back(arr[i] + 48);
        for(int i = 1;i<n;i+=2)
            b.push_back(arr[i] + 48);
        int sum = 0, c = 0;
        string ans = "";
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int i = 0;
        while(i < a.size() && i < b.size())
        {
            sum = a[i] - 48 + b[i] - 48 + c;
            if(sum > 9)
            {
                c = sum / 10;
                sum %= 10;
            }
            else
                c = 0;
            ans.push_back(sum+48);
            i++;
        }
        while(i < a.size())
        {
            sum = a[i] - 48 + c;
            if(sum > 9)
            {
                c = sum / 10;
                sum %= 10;
            }
            else
                c = 0;
            ans.push_back(sum+48);
            i++;
        }
        while(i < b.size())
        {
            sum = b[i] - 48 + c;
            if(sum > 9)
            {
                c = sum / 10;
                sum %= 10;
            }
            else
                c = 0;
            ans.push_back(sum+48);
            i++;
        }
        while(c > 0)
        {
            ans.push_back(c%10+48);
            c /= 10;
        }
        while(ans[ans.size()-1] == '0')
            ans.pop_back();
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.solve(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends
