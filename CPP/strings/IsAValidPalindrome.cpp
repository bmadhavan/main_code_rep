 Valid Palindrome

Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome.


 // 0 if not alphanumeric
    bool isPalindrome(string s) {
    
    int i = 0 ;
    int j = s.length();
    
    while ( i < j ) { 
         while ( !isalnum(s[i]) ) i++;
         while ( !isalnum(s[j]) ) j--;
         if ( i<j && toupper(s[i]) != toupper(s[j]) ) return false;
         i++; j--;
    }
    
    return true;
    }
};