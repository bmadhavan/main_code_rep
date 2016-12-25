/*
Shortest Word Distance

Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.

For example,
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

Given word1 = “coding”, word2 = “practice”, return 3.
Given word1 = "makes", word2 = "coding", return 1.

Note:
You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.

My Solution: 
Look through all the the occurances and push it an array. 
Then walk through both the arrays to find the nearest occurance. 
*/
    int shortestDistance(vector<string>& words, string word1, string word2) {
        vector<int> w1;
        vector<int> w2;
        for ( int i=0; i < words.size() ; i++ ) { 
           if ( word1.compare(words[i]) == 0) w1.push_back(i);
           else if ( word2.compare(words[i]) == 0) w2.push_back(i);
           else continue;
        }
        int result=INT_MAX;
        int i, j;
       
        for ( i=0, j=0 ; i<w1.size() && j<w2.size() ; ) {
            int diff = std::abs(w1[i] - w2[j] );
            if ( w1[i] <= w2[j]) i++; 
            else j++; 
            result= std::min( diff,  result);
        }
        return result;
    }