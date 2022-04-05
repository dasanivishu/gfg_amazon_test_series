// Given an array A[] of N positive integers. The task is to find the maximum of j - i subjected to the constraint of A[i] < A[j] and i < j.
 

// Example 1:

// Input:
// N = 2
// A[] = {1, 10}
// Output:
// 1
// Explanation:
// A[0]<A[1] so (j-i) is 1-0 = 1.

// Example 2:

// Input:
// N = 9
// A[] = {34, 8, 10, 3, 2, 80, 30, 33, 1}
// Output:
// 6
// Explanation:
// In the given array A[1] < A[7]
// satisfying the required 
// condition(A[i] < A[j]) thus giving 
// the maximum difference of j - i 
// which is 6(7-1).

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
        
    // A[]: input array
    // N: size of array
    // Function to find the maximum index difference.
    int maxIndexDiff(int A[], int N) 
    { 
        // Your code here
        int i,j;
        int greater[N],smaller[N];
        smaller[0]=A[0];//maintain min element on left side including index
        for(int i=1;i<N;i++)
        smaller[i]=min(A[i],smaller[i-1]);
        greater[N-1]=A[N-1];//maintain max element on right side including index
        for(int i=N-2;i>=0;i--)
        greater[i]=max(A[i],greater[i+1]);
        
        i=0,j=0;
        int max_diff=-1;
        while(i<N&&j<N)
        {
            if(smaller[i]<=greater[j])
            {
                max_diff=max(max_diff,j-i);
                j++;
            }
            else
            i++;
        }
        return max_diff;
    }
};

// { Driver Code Starts.
  
/* Driver program to test above functions */
int main() 
{
    int T;
    //testcases
    cin>>T;
    while(T--){
        int num;
        //size of array
        cin>>num;
        int arr[num];
        
        //inserting elements
        for (int i = 0; i<num; i++)
            cin>>arr[i];
        Solution ob;
        
        //calling maxIndexDiff() function
        cout<<ob.maxIndexDiff(arr, num)<<endl;    
        
    }
    return 0;
}   // } Driver Code Ends

