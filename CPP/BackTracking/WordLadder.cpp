/*
Word Ladder

Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the word list
For example,

Given:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]
As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Note:
Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.

Solution: 
BFS. Stating from the startWord, populate the queue with all of the neighbours in each round. 
Repeat this till you find the endword.
To remember: 
* Add the end word to the WordList.   
* Remove the word that is visited from the dictionary. 
*/ 


class Solution {
private: 
    void GetNeighbourList( string currword, unordered_set<string>& wordList, queue<string> &nlist ){ 
        for ( int i=0; i < currword.size() ; i++){
            for ( int alpha=0; alpha<=26 ; alpha++ ) {
                string newword = currword; 
                newword[i] = 'a' + alpha;
                if ( wordList.find(newword) != wordList.end() ) { 
                    nlist.push(newword);
                    wordList.erase(newword);
                }
            }
        }
    }
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        wordList.insert(endWord);
        queue<string> nlist;  // neighbours list
        GetNeighbourList( beginWord, wordList, nlist ); 
        int distance = 2; 
        while ( !nlist.empty() ){
            int len = nlist.size();
            for ( int i=0; i < len; i++ ){
                string tmp = nlist.front();
                nlist.pop();
                if (tmp == endWord) return distance;
                wordList.erase(tmp);
                GetNeighbourList( tmp, wordList, nlist );
            }
            distance++; // After every level.
        }
        return 0;
    }
};