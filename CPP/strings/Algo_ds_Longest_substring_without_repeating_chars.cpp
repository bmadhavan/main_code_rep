Given a string, find the length of the longest substring without repeating characters. 


int lengthOfLongestSubstring(string s) {
     
     int i=0, maxlen = 0, start = -1;
     unordered_map<char ,int>  mymap;
     
     while ( i < s.size() )
     {
         if ( mymap.find( s.at(i) ) != mymap.end() )
            start = max( start , mymap[s.at(i)] );
         
         mymap[s.at(i)] =  i;
         maxlen = max ( maxlen , i-start );
         i++;
     }
    return maxlen;
    }