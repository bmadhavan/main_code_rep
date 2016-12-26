/* 
Two Sum III - Data structure design

Design and implement a TwoSum class. It should support the following operations: add and find.

add - Add the number to an internal data structure.
find - Find if there exists any pair of numbers which sum is equal to the value.

For example,
add(1); add(3); add(5);
find(4) -> true
find(7) -> false
*/

class TwoSum {
private: 
  unordered_map<int, int> nums;
public:
    // Add the number to an internal data structure.
	void add(int number) {
	   nums[number]++;
	}

    // Find if there exists any pair of numbers which sum is equal to the value.
	bool find(int value) {
	    unordered_map<int, int >::const_iterator itr; 
	    for ( itr = nums.begin(); itr != nums.end() ; itr++ ) {
	        int find = value - itr->first;
	        if ( itr->first == find && itr->second > 1 ) return true;
	        else {
	            if ( nums.find(find) != nums.end() ) return true;
	        } 
	    }
	    
	    return false; 
	}
};


// Your TwoSum object will be instantiated and called as such:
// TwoSum twoSum;
// twoSum.add(number);
// twoSum.find(value);