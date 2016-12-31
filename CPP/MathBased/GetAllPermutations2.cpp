/*
Permutations II

Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]



Solution: The famous Dijkstra's incremental permutation algorithm: 
Solves probs like,
Find the next largest number.
Find the lexicographically valid next permutation. 
Find all permutations without duplicates
Find all permutations with duplicates. 

Logic: To get next perm:  eg:1342: 
First look if the number is sorted in decending order. Then this is the last permutation. There is no next. eg: 4321
Then from the last get the first element that is not in ascending/sorted order. eg:3
Then get the first element to its right that is bigger than the current number 3. eg: 4
Then swap the values. eg: 1432
Then reverse all the elements from 3 to end. eg: 1432 -- > 1423   
So: Q:1342 Ans: 1423 
*/

Class Permutations{

private:
   bool HasNextPermutation( vector<int> &nums ){
        if ( std::is_sorted_until(nums.rbegin(), nums.rend()) != nums.rend() ) return true;
        else return false;
    }
    
    void GetNextPermutation( vector<int> &nums ){
        
        auto it = std::is_sorted_until(nums.rbegin(), nums.rend());
        std::swap( *it, *std::upper_bound(nums.rbegin(), it, *it) );
        std::reverse(nums.rbegin(), it);
    }

public:    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        if ( nums.size() < 1 ) return result;
        std::sort(nums.begin(), nums.end());
        result.push_back(nums);
        while ( HasNextPermutation(nums) ) { 
            GetNextPermutation( nums );        
            result.push_back(nums);
        }
        return result;
    }
};