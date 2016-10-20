Find Minimum in Rotated Sorted Array

Suppose a sorted array is rotated at some pivot unknown to you beforehand.
(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
Find the minimum element.
You may assume no duplicate exists in the array.

My solution:
Binary search. 
In every loop,
if the start element is less than middle element. Then change the range from middle to last.
if the start element is greater than middle element. Then change the range from  start to middle.

    int findMin(vector<int>& nums) {
        int l, r;
        l = 0;
        r = nums.size() - 1;
        
        if ( nums[l] < nums[r] )
            return nums[0];
            
        while ( 1 )
        {
            if ( (l+r)/2 == l || (l+r)/2 == r )
                return nums[r];
            
            int val = nums[(l+r)/2];
            if ( val > nums[l] )
                l = (l+r)/2;
            else if ( val < nums[l] )
                r = (l+r)/2;
            
            
        }
    }

