Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.

Examples:
pattern = "abba", str = "dog cat cat dog" should return true.
pattern = "abba", str = "dog cat cat fish" should return false.
pattern = "aaaa", str = "dog cat cat dog" should return false.
pattern = "abba", str = "dog dog dog dog" should return false.
Notes:
You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single space.


My solution: 
Use an unordered map for O(1) lookup of every pattern to check if the words match. 
Use a Ordered map for O(log n) lookup of duplicate pattern i.e. same word for multiple pattern.

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        /* Unordered map for O(1) lookup of every pattern */
        std::unordered_map<int,string> mymap; 
        /* Ordered map for O(log n) lookup of duplicate pattern 
           macthing the same word. i.e. pattern = "abba", str = "dog dog dog dog" should return false. */
        std::map<string,int> omap;
      
        std::istringstream iss (str); 
        string word;
        
        for ( int i=0 ; i < pattern.size() ; i++) {
            int bucket = pattern.at(i) - 'a' ; 
            std::unordered_map<int,string>::const_iterator got = mymap.find (bucket);
            iss >> word;
            if ( got == mymap.end() ) {
                // What if some other key points to this word.
                if ( omap.find(word) != omap.end() ) 
                    return false;
                else 
                    omap.insert( {word, 1});
                mymap.insert( {bucket, word } );
            } else {
                string old = got->second;
                int ret = word.compare(old);
                if ( ret != 0)
                  return false;
            }
        }
       
       if (iss >> word )
          return 0;
       else
        return 1;
    }
};