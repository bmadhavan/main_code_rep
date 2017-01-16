/* 
Minimum Window Substring
 
Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

For example,
S = "ADOBECODEBANC"
T = "ABC"
Minimum window is "BANC".

Note:
If there is no such window in S that covers all characters in T, return the empty string "".

If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.

*/ 

 string minWindow(string s, string t) {
        if ( t.size() == 0 ) return s.substr(0,0);
        unordered_map<char, int> mymap; 
        for ( auto c : t ) mymap[c]++; 
        int start = 0, end = 0, counter =t.size(), begin=0; 
        int mini=INT_MAX; 
        
        while ( end < s.size() ) { 
          if ( mymap [s[end]] > 0 ) counter--;
          mymap[s[end]]--;
          end++;
          
          while ( counter == 0 ) { 
              if ( mini > end-begin) { 
                  mini = end-begin;
                  start = begin;
              }
              mymap[s[begin]]++;
              if ( mymap[s[begin]] > 0 ) counter++;
              begin++;
          }
        }
        if ( mini != INT_MAX)
            return s.substr(start, mini );
        else 
            return s.substr(0, 0 );
    }