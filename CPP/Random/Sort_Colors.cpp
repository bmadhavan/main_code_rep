Sort Colors

Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.


void sortColors(vector<int>& nums) {
        int i, index, k=nums.size()-1; 
        
        for (i=0, index=0 ; index <= k; ){
            if ( index > i && nums[i] x] ) swap(nums[i++], nums[index]);
            else if ( index < k && nums[index] > nums[k] ) swap(nums[index], nums[k--]);
            else index++;
        }
        return;
    }