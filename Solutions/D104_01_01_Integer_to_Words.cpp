// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    string ones[20] = { "", "one ", "two ", "three ", "four ", "five ", "six ", "seven ", "eight ", "nine ", "ten ", "eleven ", "twelve ", "thirteen ", "fourteen ", "fifteen ", "sixteen ", "seventeen ", "eighteen " ,"nineteen "};
    string tens[10] = {"", "", "twenty ", "thirty ", "forty ", "fifty " , "sixty ", "seventy ", "eighty ", "ninety " };

    string ntw(int n, string s)
    {
        string str = "";
        if(n > 19)
            str += tens[n/10]+ ones[n%10];
        else
            str += ones[n];
        if(n)
            str += s;
        return str;
    }

    string convertToWords(long n) {
        // code here
        string ans;
        ans += ntw((n/10000000), "crore ");
        ans += ntw((n/100000)%100, "lakh ");
        ans += ntw((n/1000)%100, "thousand ");
        ans += ntw((n/100)%10, "hundred ");
        if(n > 100 && n%100)
        {
            ans += "and ";
        }
        ans += ntw((n%100), "");
        return ans;
        
        
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        long n;
        cin >> n;
        Solution ob;
        auto ans = ob.convertToWords(n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends
