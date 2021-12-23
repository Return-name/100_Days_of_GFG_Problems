// { Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;



/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


 // } Driver Code Ends
class Solution
{
    
    void merge_sort(vector<int> &arr, int a, int b)
    {
        if(a >= b)
    		return;
    	
    	int m = (a+b)/2;
    	merge_sort(arr, a, m);
    	merge_sort(arr, m+1, b);
    
    	int i = a;
    	int j = m+1;
    
    	vector<int> s(b-a+1);
    	int c = 0;
    	int ai, aj;
    	while(i <= m && j <= b) 
    	{
    		if(arr[i] <= arr[j])
    		{
    			s[c++] = arr[i];
    			i++;
    		}
    		else
    		{
    			s[c++] = arr[j];
    			j++;
    		}
    	}
    	while(i <= m)
    	{
    	    s[c++] = arr[i];
    	    i++;
    	}
    	while(j<=b)
    	   {
    	       s[c++] = arr[j];
    	       j++;
    	   }
    	i = 0;
    	for(int k = a;k<=b;k++)
    	{
    		arr[k] = s[i];
    		i++;
    	}
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {
        //code here
        if(r-l == 0)
            return;
        vector<int> v(r-l+1);
        for(int i = l;i<=r;i++)
            v[i-l] = arr[i];
        merge_sort(v, 0, v.size()-1);
        for(int i = l;i<=r;i++)
            arr[i] = v[i-l];
    }
};

// { Driver Code Starts.


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}  // } Driver Code Ends
