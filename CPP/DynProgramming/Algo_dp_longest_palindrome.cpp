 string longestPalindrome(string s) {
        int size = s.length();
        bool dp[size][size] = {0};
        int max_len=1;
        int longest_begin=0;
        int i, j;
        
        // Set true for 1 char;
        for ( i=0; i < size; i++ ) {
            dp[i][i] = true;
        }
        
        //Test and set palidrome for 2 chars. 
        for ( i=0; i < size-1; i++ ) {
            if ( s[i] == s[i+1] ) {
                dp[i][i+1] = true;
                max_len = 2;
                longest_begin = i;
            }
        }
        
        //Test and set palindrome for 3 or more. 
        for ( int len = 3 ; len <= size; len++ ) {
            for( i = 0; i < ( size - len + 1 ) ; i++ ) {
                j = i + len - 1; 
                if ( s[i] == s[j] && dp[i+1][j-1] ) {
                    dp[i][j] = true;
                    max_len = len;
                    longest_begin = i;
                }
            }
        }
        
        return s.substr(longest_begin, max_len);
        
    }