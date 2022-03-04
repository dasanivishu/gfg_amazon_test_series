// We are given an array of integers and a range, we need to find whether the subarray which falls in this range has values in the form of a mountain or not. All values of the subarray are said to be in the form of a mountain if either all values are increasing or decreasing or first increasing and then decreasing. More formally a subarray [a1, a2, a3 … aN] is said to be in form of a mountain if there exists an integer K, 1 <= K <= N such that,
// a1 <= a2 <= a3 .. <= aK >= a(K+1) >= a(K+2) …. >= aN
// You have to process Q queries. In each query you are given two integer L and R, denoting starting and last index of the subarrays respectively.

// Example 1:

// Input:
// N = 8
// a[] = {2,3,2,4,4,6,3,2}
// Q = 2
// Queries = (0,2), (1,3)
// Output:
// Yes
// No
// Explanation: For L = 0 and R = 2, a0 = 2,
// a1 = 3 and a2 = 2, since they are in the
// valid order,answer is Yes.
// For L = 1 and R = 3, a1 = 3, a2 = 2 and
// a3 = 4, since a1 > a2 and a2 < a4 the
// order isn't valid, hence the answer is
// No.
// Your Task:

// Complete the function processQueries() which takes the array, size of array queries and number of queries as parameter. It should return a vector/ArrayList/array (depending upon language cpp/Java/Python) of boolean values, true if the subarray is in mountain form, false otherwise. The driver code will print "Yes" if the returned value is true, otherwise "No".

// Expected Time Complexity: O(N + Q).
// Expected Auxiliary Space: O(N).
 
//  Approach: The problem has multiple queries so for each query the solution should be calculated with least possible time complexity. So create two extra spaces of the length of the original array. For every element find the last index on the left side which is increasing i.e. greater than its previous element and find the element on the right side will store the first index on the right side which is decreasing i.e. greater than its next element. If these value can be calculated for every index in constant time then for every given range the answer can be given in constant time.
// Algorithm: 
// Create two extra spaces of length n,left and right and a extra variable lastptr
// Initialize left[0] = 0 and lastptr = 0
// Traverse the original array from second index to the end
// For every index check if it is greater than the previous element, if yes then update the lastptr with the current index.
// For every index store the lastptr in left[i]
// initialize right[N-1] = N-1 and lastptr = N-1
// Traverse the original array from second last index to the start
// For every index check if it is greater than the next element, if yes then update the lastptr with the current index.
// For every index store the lastptr in right[i]
// Now process the queries
// for every query l, r, if right[l] >= left[r] then print yes else no
// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends


class Solution{
  public:
    bool isSubArrayMountainForm(int a[],int left[],int right[],int l,int r)
    {
        return(right[l]>=left[r]);
    }
    
    vector<bool> processQueries(int arr[], int N, vector<pair<int, int>> &queries,
                                int q) {
        // code here
        vector<bool>result;
        int left[N],right[N];
        // For every element find the last index on the left side which is increasing 
        // i.e. greater than its previous element and find the element on the right side 
        // will store the first index on the right side which is decreasing i.e. greater than its next element. 
        
        left[0]=0;
        int lastIncr=0;
        for(int i=1;i<N;i++)
        {
           if(arr[i]>arr[i-1])
           lastIncr=i;
           left[i]=lastIncr;
        }
        right[N-1]=N-1;
        int firstdecr=N-1;
        for(int i=N-2;i>=0;i--)
        {
            if(arr[i]>arr[i+1])
            firstdecr=i;
            right[i]=firstdecr;
        }
        for(int i=0;i<q;i++)
        {
            result.push_back(isSubArrayMountainForm(arr,left,right,queries[i].first,queries[i].second));
        }
        return result;
        
    }
};

// { Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, i, q;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cin >> q;
        vector<pair<int, int>> queries(q);
        for (i = 0; i < q; i++) {
            cin >> queries[i].first >> queries[i].second;
        }
        Solution obj;
        auto v = obj.processQueries(a, n, queries, q);
        for (bool u : v) {
            cout << (u ? "Yes\n" : "No\n");
        }
    }
    return 0;
}  // } Driver Code Ends
