/*Max sum in the configuration
Given an array(0-based indexing), you have to find the max sum of i*A[i] where A[i] is the element at index i in the array. The only operation allowed is to rotate(clock-wise or counter clock-wise) the array any number of times.
Example 1:
Input:
N = 4
A[] = {8,3,1,2}
Output: 29
Explanation: Above the configuration
possible by rotating elements are
3 1 2 8 here sum is 3*0+1*1+2*2+8*3 = 29
1 2 8 3 here sum is 1*0+2*1+8*2+3*3 = 27
2 8 3 1 here sum is 2*0+8*1+3*2+1*3 = 17
8 3 1 2 here sum is 8*0+3*1+1*2+2*3 = 11
Here the max sum is 29 
Your Task:
Your task is to complete the function max_sum which takes two arguments which is the array A [ ] and its size and returns an integer value denoting the required max sum.
Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

*/
//Brute Force:Check for all Rotation

// A Naive C++ program to find maximum sum rotation
#include<bits/stdc++.h>

using namespace std;

// Returns maximum value of i*arr[i]
int maxSum(int arr[], int n)
{
   // Initialize result
   int res = INT_MIN;

   // Consider rotation beginning with i
   // for all possible values of i.
   for (int i=0; i<n; i++)
   {

     // Initialize sum of current rotation
     int curr_sum = 0;

     // Compute sum of all values. We don't
     // actually rotate the array, instead of that we compute the
     // sum by finding indexes when arr[i] is
     // first element
     for (int j=0; j<n; j++)
     {
         int index = (i+j)%n;
         curr_sum += j*arr[index];
     }

     // Update result if required
     res = max(res, curr_sum);
   }

   return res;
}

// Driver code
int main()
{
    int arr[] = {8, 3, 1, 2};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << maxSum(arr, n) << endl;
    return 0;
}
//Optimised Approach:O(N)
/*Algorithm: 
The idea is to compute the value of a rotation using values of previous rotation. When an array is rotated by one, following changes happen in sum of i*arr[i]. 
Multiplier of arr[i-1] changes from 0 to n-1, i.e., arr[i-1] * (n-1) is added to current value.
Multipliers of other terms is decremented by 1. i.e., (cum_sum - arr[i-1]) is subtracted from current value where cum_sum is sum of all numbers.
next_val = curr_val - (cum_sum - arr[i-1]) + arr[i-1] * (n-1);
next_val = Value of ∑i*arr[i] after one rotation.
curr_val = Current value of ∑i*arr[i] 
cum_sum = Sum of all array elements, i.e., ∑arr[i].
Lets take example {1, 2, 3}. Current value is 1*0+2*1+3*2= 8. Shifting it by one will make it {2, 3, 1} and next value will be 8 - (6 - 1) + 1*2 = 5 which is
same as 2*0 + 3*1 + 1*2*/
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int max_sum(int A[],int N);

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        int A[N];
        for(int i=0;i<N;i++)
        {
            cin>>A[i];
        }

        cout<<max_sum(A,N)<<endl;
        /*keeping track of the total sum of the array*/

    }
}
// } Driver Code Ends


/*You are required to complete this method*/
int max_sum(int A[],int N)
{
//Your code here
int sum=0;
int curr_val=0;
for(int i=0;i<N;i++)
{
    sum+=A[i];
    curr_val+=i*A[i];
}
int res=curr_val;
for(int i=1;i<N;i++)
{
    //Compute next value using previous in O(1) time
    int next_val=curr_val-(sum-A[i-1])+A[i-1]*(N-1);
    //Update curr_value
    curr_val=next_val;
    //Update result if required
    res=max(res,curr_val);
}
return res;

}
