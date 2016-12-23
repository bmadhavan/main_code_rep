Move Zeroes

Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].

Note:
You must do this in-place without making a copy of the array.
Minimize the total number of operations.

/* Solution 1 - Maintain the order */
  void moveZeroes(vector<int>& nums) {
  int zi=0;
  int nzi=0;
  int size=nums.size()-1;
  
  while ( nzi <= size ) { 
      while ( zi < size && nums[zi] != 0 ) zi++;
      while ( nzi < size && nums[nzi] == 0 ) nzi++;
      if ( zi < nzi ) swap ( nums[nzi++] , nums[zi++]);
      else nzi++;
  }  
}

/* Solution 2: If the order need not be maintained. Complexity: O(n)     
    int zi=0;
    int nzi=nums.size()-1;
    
        while ( nzi >= zi ) {
            while ( nums[zi] != 0 ) ++zi;
            while ( nums[nzi] == 0 ) --nzi;
            if ( nzi > zi ) std::swap(nums[nzi--], nums[zi++]);
        }
*/