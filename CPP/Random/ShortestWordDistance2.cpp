This is a follow up of Shortest Word Distance. The only difference is now you are given the list of words and your method will be called repeatedly many times with different parameters. How would you optimize it?

Design a class which receives a list of words in the constructor, and implements a method that takes two words word1 and word2 and return the shortest distance between these two words in the list.

For example,
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

Given word1 = “coding”, word2 = “practice”, return 3.
Given word1 = "makes", word2 = "coding", return 1.

Note:
You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.

class WordDistance {
public:
    unordered_map<string, vector<int>> mymap;
    WordDistance(vector<string>& words) {
        for ( int i=0; i < words.size(); i++ ) { 
            mymap[words[i]].push_back(i);
        }
    }

    int shortest(string word1, string word2) {
        int result=INT_MAX;
        int i, j;
        vector<int> w1=mymap[word1];
        vector<int> w2=mymap[word2];
       
        for ( i=0, j=0 ; i<w1.size() && j<w2.size() ; ) {
            int diff = std::abs(w1[i] - w2[j] );
            if ( w1[i] <= w2[j]) i++; 
            else j++; 
            result= std::min( diff,  result);
        }
        return result;
    }
};
