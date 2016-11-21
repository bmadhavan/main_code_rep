Longest Increasing Subsequence

Given an unsorted array of integers, find the length of longest increasing subsequence.

For example,
Given [10, 9, 2, 5, 3, 7, 101, 18],
The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4. Note that there may be more than one LIS combination, it is only necessary for you to return the length.
Your algorithm should run in O(n2) complexity.


My solution: Create an array to store the max length of subarray for each element. 
Go through all the elements in the list before the current element to compute which combination gives a better max subsequence value. 
Set he current max.

Complexity: O(n^2) 


    int lengthOfLIS(vector<int>& nums) {
        int dp[nums.size()+1] = {0};
        int max=0;
        if ( nums.size() == 0 ) return max; 
        max = dp[0] = 1;
		
        for ( int i=1; i < nums.size() ; ++i ) {
            for (int j = 0; j < i; ++j) { 
                if ( nums[j] < nums[i] && dp[j] >= dp[i] ) {
                    dp[i] = dp[j] + 1;
                    max = std::max(max, dp[i]);
                }
            }
            if ( dp[i] == 0 ) dp[i] = 1;
        }
        return max;
    }