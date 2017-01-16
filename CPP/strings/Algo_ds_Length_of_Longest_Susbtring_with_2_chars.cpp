/*
Longest Substring with At Most Two Distinct Characters

Given a string, find the length of the longest substring T that contains at most 2 distinct characters.

For example, Given s = “eceba”,

T is "ece" which its length is 3.
*/

    int lengthOfLongestSubstringTwoDistinct(string s) {
          if ( s.size() < 3 ) return s.size();
        unordered_map<char, int> mymap; 
        int start = 0, end = 0, counter = 0, begin=0; 
        int max=INT_MIN; 
        
        while ( end < s.size() ) {
            if ( mymap[s[end]] == 0 ) counter++;
            mymap[ s[end] ]++;
            end++;
            
            while ( counter > 2 ){
                mymap[s[start]]--;
                if ( mymap[s[start]] == 0 ) counter--; 
                start++;  
            }
            max = std::max(max, end-start);
        }
         return max;
    }
	
