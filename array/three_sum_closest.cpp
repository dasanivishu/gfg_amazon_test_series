// Given an array Arr of N numbers and another number target, find three integers in the array such that the sum is closest to target. Return the sum of the three integers.

// Example 1:

// Input:
// N = 6, target = 2
// A[] = {-7,9,8,3,1,1}
// Output: 2
// Explanation: There is one triplet with sum
// 2 in the array. Triplet elements are -7,8,
// 1 whose sum is 2.

// Example 2:

// Input:
// N = 4, target = 13
// A[] = {5,2,7,5}
// Output: 14
// Explanation: There is one triplet with sum
// 12 and other with sum 14 in the array.
// Triplet elements are 5, 2, 5 and 2, 7, 5
// respectively. Since abs(13-12) ==
// abs(13-14) maximum triplet sum will be
// preferred i.e 14.

// { Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

// arr : given vector of elements
// target : given sum value

class Solution{
  public:
    int threeSumClosest(vector<int> arr, int target) {
        // Your code goes here
        int start,end,sum;
        int diff1=INT_MAX,diff2=INT_MAX;
        sort(arr.begin(),arr.end());
        int n=arr.size();
        for(int i=0;i<n;i++)
        {
            start=i+1;
            end=n-1;
            while(start<end)
            {
                sum=arr[i]+arr[start]+arr[end];
                if(sum==target)
                return sum;
                else if(sum>target)
                {
                    end--;
                    diff1=min(diff1,sum-target);
                }
                else//target>sum
                {
                    start++;
                    diff2=min(diff2,target-sum);
                }
                
            }
        }
        if(diff1<diff2)
        return target+diff1;
        
        if(diff1==diff2)
        return target+diff1;//in case of diff1,sum>target
        
        return target-diff2;//in case of diff2,target>sum
        
    }
};



// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while(t--) {
        
        int n,target;
        cin >> n >> target;
        
        vector<int> vec(n);
        
        for(int i = 0 ; i < n ; ++ i ) 
            cin >> vec[i];
        Solution obj;
        cout << obj.threeSumClosest(vec, target) << "\n";
    }
}

//Position this line where user code will be pasted.
  // } Driver Code Ends
