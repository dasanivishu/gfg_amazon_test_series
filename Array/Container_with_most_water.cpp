// Given N non-negative integers a1,a2,....an where each represents a point at coordinate (i, ai). N vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i,0). Find two lines, which together with x-axis forms a container, such that it contains the most water.

// Example 1:

// Input:
// N = 4
// a[] = {1,5,4,3}
// Output: 6
// Explanation: 5 and 3 are distance 2 apart.
// So the size of the base = 2. Height of
// container = min(5, 3) = 3. So total area
// = 3 * 2 = 6.

// Example 2:

// Input:
// N = 5
// a[] = {3,1,2,4,5}
// Output: 12
// Explanation: 5 and 3 are distance 4 apart.
// So the size of the base = 4. Height of
// container = min(5, 3) = 3. So total area
// = 4 * 3 = 12.

// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;
// int maxArea(int A[], int len);

 // } Driver Code Ends
//User function template for C++

long long maxArea(long long A[], int len)
{
    // Your code goes here
    long long res=0;
    long long  i=0,j=len-1;
    long long temp;
    while(i<j)
    {
        temp=min(A[i],A[j])*(j-i);
        res=max(res,temp);
        if(A[i]<A[j])
        i++;
        else
        j--;
    }
    return res;
}

// { Driver Code Starts.

// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--)
    {
        int n;
        cin>>n;
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cout<<maxArea(arr,n)<<endl;
    }
return 0;
}
  // } Driver Code Ends
