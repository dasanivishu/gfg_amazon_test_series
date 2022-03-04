// Given an array A of N integers, find any 3 elements in it such that A[i] < A[j] < A[k] and i < j < k.

// Example 1:

// Input:
// N = 5
// A[] = {1,2,1,1,3}
// Output: 1
// Explanation: a sub-sequence 1 2 3 exist.
// Example 2:

// Input:
// N = 3
// A[] = {1,1,3}
// Output: 0
// Explanation: no such sub-sequence exist.
// Your Task:
// Your task is to complete the function find3Numbers which finds any 3 elements in it such that A[i] < A[j] < A[k] and i < j < k. You need to return them as a vector/ArrayList/array (depending on the language cpp/Java/Python), if no such element is present then return the empty vector of size 0.

// Note: The output will be 1 if the sub-sequence returned by the function is present in array A else 0. If the sub-sequence returned by the function is not in the format as mentioned then the output will be -1.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(N)
/*Solution: First find two elements arr[i] & arr[j] such that arr[i] < arr[j]. Then find a third element arr[k] greater than arr[j].
Approach: We can think of the problem in three simple terms.
First we only need to find two elements arr[i] < arr[j] and i < j. This can be done in linear time with just 1 loop over the range of the array. For instance, while keeping track of the min element, its easy to find any subsequent element that is greater than it. Thus we have our arr[i] & arr[j].
Secondly, consider this sequence - {3, 4, -1, 0, 2}. Initially min is 3, arr[i] is 3 and arr[j] is 4. While iterating over the array we can easily keep track of min and eventually update it to -1. And we can also update arr[i] & arr[j] to lower values i.e. -1 & 0 respectively.
Thirdly, as soon as we have arr[i] & arr[j] values, we can immediately start monitoring the subsequent elements in the same loop for an arr[k] > arr[j]. Thus we can find all three values arr[i] < arr[j] < arr[k] in a single pass over the array.
Algorithm: Iterate over the length of the array. Keep track of the min. As soon as the next iteration has an element greater than min, we have found our arr[j] and the min will be saved as arr[i]. Continue iterating until we find an element arr[k] which is greater than arr[j]. 
In case the next elements are of lower value, then we update min, arr[i] and arr[j] to these lower values, so as to give us the best chance to find arr[k].*/
//Code:
// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

bool isSubSequence(vector<int> &v1, vector<int> &v2, int n, int m) {

    if (m == 0) return true;
    if (n == 0) return false;

    if (v1[n - 1] == v2[m - 1]) return isSubSequence(v1, v2, n - 1, m - 1);

    return isSubSequence(v1, v2, n - 1, m);
}


 // } Driver Code Ends
/*The function returns a vector containing the
increasing sub-sequence of length 3 if present
else returns an empty vector */
class Solution{
  public:
    vector<int> find3Numbers(vector<int> arr, int N) {
        // Your code here
        vector<int>greater(N),smaller(N);
        //Maintain two array smaller and greater ,smaller[i] tracks the smaller element of array[i] on left side
        //and greater[i] tracks the greater element of array[i] on right side
        int min=arr[0];
        for(int i=1;i<N;i++)
        {
            if(arr[i]<=min)
            {
                min=arr[i];
                smaller[i]=0;
            }
            else
            {
                smaller[i]=min;
            }
        }
        int max=arr[N-1];
        for(int i=N-2;i>0;i--)
        {
            if(arr[i]>=max)
            {
                greater[i]=0;
                max=arr[i];
            }
            else
            {
                greater[i]=max;
            }
        }
        vector<int>res;
        for(int i=1;i<N-1;i++)
        {
            if(smaller[i]&&greater[i])
            {
                res.push_back(smaller[i]);
                res.push_back(arr[i]);
                res.push_back(greater[i]);
                return res;
            }
        }
        return res;
    }
};

// { Driver Code Starts.

// Driver program to test above function
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution obj;
        auto res = obj.find3Numbers(a, n);

        // wrong format output
        if (!res.empty() and res.size() != 3) {
            cout << -1 << "\n";
        }

        if (res.empty()) {
            cout << 0 << "\n";
        } else if ((res[0] < res[1] and res[1] < res[2]) and
                   isSubSequence(a, res, n, res.size())) {
            cout << 1 << "\n";
        } else {
            cout << -1 << "\n";
        }
    }

    return 0;
}  // } Driver Code Ends
