// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    // n: input to count the number of set bits
    //Function to return sum of count of set bits in the integers from 1 to n.
    int countSetBits(int n)
    {
        // Your logic here
        n++;
        long long int ans = 0;
        for(int i = 0;i<=30;i++)
        {
            int gl = 1<<(i+1);
            int gl2 = 1<<i;
            ans += (n/gl)*(1<<i);
            int n2 = n;

            if(n > gl)
                n2 = (n%gl);
            
            if((n % gl) != 0 && n2 > gl2)
                ans +=  n2 - gl2;
        }
        return ans;
    }
};


// { Driver Code Starts.

// Driver code
int main()
{
	 int t;
	 cin>>t;// input testcases
	 while(t--) //while testcases exist
	 {
	       int n;
	       cin>>n; //input n
	       Solution ob;
	       cout << ob.countSetBits(n) << endl;// print the answer
	  }
	  return 0;
}
  // } Driver Code Ends
