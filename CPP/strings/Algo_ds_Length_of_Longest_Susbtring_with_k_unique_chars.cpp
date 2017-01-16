/*
Longest Substring with At Most K Distinct Characters
 
Given a string, find the length of the longest substring T that contains at most k distinct characters.

For example, Given s = “eceba” and k = 2,

T is "ece" which its length is 3. 
*/


 int lengthOfLongestSubstringKDistinct(string s, int k) {
        if ( s.size() <= k ) return s.size();
        unordered_map<char, int> mymap; 
        int start = 0, end = 0, counter = 0; 
        int max=INT_MIN; 
        
        while ( end < s.size() ) {
            if ( mymap[s[end]] == 0 ) counter++;
            mymap[ s[end] ]++;
            end++;
            
            while ( counter > k ){
                mymap[s[start]]--;
                if ( mymap[s[start]] == 0 ) counter--; 
                start++;  
            }
            max = std::max(max, end-start);
        }
         return max;
    }
	