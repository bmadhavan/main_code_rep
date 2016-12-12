Letter Combinations of a Phone Number


Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.

Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

My Solution: 
Iterative backtracking. 
First go through all combinations. and insert them in tmp. Then only return the ones that are complete.  


class Solution {
    vector<string> s = { "_" , "" , "abc", "def" , "ghi" , "jkl" , "mno" , "pqrs" , "tuv" , "wxyz" };
        
public:
    vector<string> letterCombinations(string digits) {
        vector<string> tmp(1, "");
        vector<string> result;
        if ( digits.size() == 0 ) return result;
        int c;
        int curr=0;
        for ( int i=0; i < digits.size(); i++ ){
            int count = tmp.size();
            int n = digits[i] - '0';
            for ( int j = 0; j < count ; j++) { 
                c = s[n].size();
                while ( c-- ) {
                     string t = tmp[j];
                     t.append(1, s[n][c] );
                     tmp.push_back(t);
                }
            }
        }
        int ans = digits.size();
        for ( int k=0; k < tmp.size() ; k++ ) { 
            if ( tmp[k].size() == ans ) result.push_back( tmp[k] );
        }
        return result;
    }
};