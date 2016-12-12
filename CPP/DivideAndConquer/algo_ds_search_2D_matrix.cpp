Search a 2D Matrix

Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
For example,

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
Given target = 3, return true.


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
       int m = matrix.size();
       int n = m>0?matrix[0].size():0;
       int l, r;
       for ( l=0, r = m*n -1 ; l <= r ; ) { 
        int mid = l+(r-l)/2;
        if ( matrix[mid/n][mid%n] == target ) return true; 
        else if  ( matrix[mid/n][mid%n] < target ) l = mid+1;
        else r = mid - 1;
       }
       return false;
    }
};