Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.
For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code".

My solution: 
Maintain a flag to keep track upto which letter a word can be made. 
Then try all possible combinations from every valid starting point. 
Return as soon as you hit the case where the last letter is part of a word.  



    bool wordBreak(string s, unordered_set<string>& wordDict) {
        bool isword[s.length()+1] = { false };
        isword[0] = isword[s.length()] = 1;
        
        for ( int i=1; i <= s.length() ; i++ ) {
            for ( int j=1; i+j <= s.length()+1; j++ ) {
               if ( isword[i-1] == true ) { 
                 string t = s.substr(i-1,j);
                    if ( wordDict.find(t) != wordDict.end() ) { 
                        isword[i-1+j] = true;
                        //cout << ":" << i-1+j << endl;
                        if ( i != 1 && ((i-1+j) == s.length()) )
                            return true;
                    }
                }   
            }
        }
        return false;
    }