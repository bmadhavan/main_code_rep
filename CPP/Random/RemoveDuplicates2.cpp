Remove Duplicates from Sorted Array II

Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array nums = [1,1,1,2,2,3],

Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3. It doesn't matter what you leave beyond the new length.

My Solution: O(n)

// Pointer 'start' will point to the start of the new element to be examined. 
// Counter 'count' will count the number of occurances. 
// Pointer 'size' will point to the current element that needs to replaced i.e. the actual size.

    int removeDuplicates(vector<int>& nums) {
        int start=0;
        int count=1;
        int size=0;
        int len = nums.size()-1;
        if ( nums.size() < 2 ) return nums.size();
        
        for ( ; start <= len ;  ) { 
           while ( start+count <= len &&  nums[start] == nums[start+count] ) count++;
        
		   for ( int i=0; i < min(count,2); i++ ) 
                nums[size+i] = nums[start+i];  
					
           if ( start+count > len ) return (size+min(count,2));
              
           size = size + min(count,2);
           start=start+count;
           count=1;
        }
        return size; 
    }