Find, Needle in the haystack. 

Brute Force: O ( nm ) where n is len of text and m is len of pattern
KMP: O ( m + n ) 
Precompute a array of Longest Proper Prefix which is also a suffix   

class Solution {
public:
    void prefix_tbl( string needle, vector<int> &tbl ) { 
       tbl[0] = 0; /* The longest prefix for 1st char is 0 */  
       int lps_len=0;
       for ( int i=1; i < needle.length() ; ) { 
           /* Match: If current prefix and lps match then lps_len++ and i++  */
           if ( needle[i] == needle[lps_len] ) tbl[i++] = ++lps_len;
           /* No match. lps_len == 0. Move on. */ 
           else if ( lps_len == 0 ) tbl[i++] = 0; 
           /* NO match but lps_len is non-zero then stay, use previous lps_len */
           else lps_len = tbl[lps_len-1];
       }
    }
    
    int strStr(string haystack, string needle) {
        //Find needle in the haystack
        if ( !needle.length() )
            return 0;
        if ( !haystack.length() || needle.length() > haystack.length() )
            return -1;
        /* KMP Algo */     
        int m = needle.length();
        int n = haystack.length();
        vector<int> tbl(m);
        int j=0, i;
        prefix_tbl(needle, tbl);
        
        for ( i=0; i < n && j < m ; i++ ) { 
        /* Case 1: If j > 0 and pattern does not match, move j to previous value from tbl */    
            while ( j > 0 && haystack[i] != needle[j] ) j = tbl[j-1];
        /* Case 2: If pattern matches */ 
            if (  haystack[i] == needle[j]  ) j++;
        }
        
        if ( j == m ) return (i-j);
        else return -1;
    }
        
/* Brute Force start        
        for ( int i = 0 ;  i < haystack.size() ; ++i ) {
            for ( int j=0; j < needle.length() ; ++j ) { 
                if ( haystack[i+j] != needle[j] )
                    break;
                else if ( j == needle.length()-1 )
                    return i;
            }
        }
        return -1;
    }
Brute Force End */
};