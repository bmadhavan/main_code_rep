/* Nested List Weight Sum II

Given a nested list of integers, return the sum of all integers in the list weighted by their depth.
Each element is either an integer, or a list -- whose elements may also be integers or other lists.
Different from the previous question where weight is increasing from root to leaf, now the weight is defined from bottom up. i.e., the leaf level integers have weight 1, and the root level integers have the largest weight.
Example 1:
Given the list [[1,1],2,[1,1]], return 8. (four 1's at depth 1, one 2 at depth 2)

Example 2:
Given the list [1,[4,[6]]], return 17. (one 1 at depth 3, one 4 at depth 2, and one 6 at depth 1; 1*3 + 4*2 + 6*1 = 17)

*/

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
 
 /* My Approach Explained: 
Loop through the list of all elements in the given input vector and use a vector of integers to store the result at each depth. 
Then finally loop through the result vector and multiply if by the height. 
In DFS loop:
If the element is an integer add it to the sum of current depth in the result vector. 
If not call recursively the routine till you hit an integer. Incerese the depth at every call.  

*/
class Solution {
public:
  void depthSumInverse( NestedInteger& nestedList, int depth, vector<int> &res ) { 
        if ( res.size() < depth+1 ) res.resize(depth+1);
        
           if ( nestedList.isInteger() ) { 
                res[depth] += nestedList.getInteger(); 
           } else {
                for ( auto new_ni : nestedList.getList()  ) 
                    depthSumInverse( new_ni, depth+1, res );
           }
  }
  
    int depthSumInverse(vector<NestedInteger>& nestedList) {
         vector<int> result(0);
         for ( int i=0; i < nestedList.size() ; i++ ) 
            depthSumInverse(nestedList[i], 0, result );
            
          
         // Post processing
         int sum=0, height;
         for ( int depth = result.size()-1 , height=1 ; depth >= 0 ; depth--, height++ ) 
             sum += result[depth] * height;
        
        return sum;
    }
};