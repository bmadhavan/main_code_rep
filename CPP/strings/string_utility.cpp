/*
 * str_trim.cpp
 *
 *  Created on: Aug 16, 2015
 *      Author: bmadhava
 */

/* Here I will try to build a small utility around the existing
 * string class in C++ to convert strings into different formats efficiently
*/

using namespace std;
#include <iostream>
#include <cstring>
#include <vector>
#include <unordered_map>

/* Reverse the string blindly */
void str_reverse( string &s, int start , int end )
	    {
	        char t;
	        while ( start < end )
	        {
	            t = s[start];
	            s[start++] = s[end];
	            s[end--] = t;
	        }
	        return;
	    }

/* Reverse a sentence but not internally the words.
 * Also remove any redundant spaces.
 * Input:  My name is Robert
 * Output: Robert is name My.
 * */
int StrReverseASentence( string s )
{
	        int size = s.length();
	        if ( size <= 2 ){
	            if ( s[0] == ' ' )
	                s[0] == '\0' ;
	            return 1;
	        }

	        /* Reverse entire string first. */
	        str_reverse( s, 0, size );

	        /* Now reverse only words. */
	        int i=0;
	        while ( i < size )
	        {
	            if ( s[i] == ' ' )
	            {
	            	;
	            }
	            else
	            {
	                int start = i;
	                while ( i < size && s[i] != ' ')
	                    i++;
	                str_reverse( s, start, i-1);
	            }
	            i++;
	        }

	        /* Remove all redundant spaces. */
	        i=0;
	        int curr=0;
	        while ( i+1 < size )
	        {
	            if ( s[i] == ' ' && s[i] == s[i+1] ){
	                  ++i;
	            } else {
	                s[curr++] = s[i++];
	            }
	        }
	        s.resize(curr);
	        cout << " the string is:'" << s <<  "'"<< endl;
	        return 1;
}

#ifdef STR1

/*
Given a string remove all extra spaces:
Input:   "    geeks     for ge  eeks  "
Output:  "geeks for ge eks"
*/

inline bool is_special_chr( int c)
{
	if ((c > 0 && c < 10) || (c > 17 && c < 43) || (c > 49 && c < 75))
		return 0;
	return 1;
}

int main()
{
	string my_str("\"    geeks     for ge    eeks  \"");
	string new_str;
	int sp=0;
	for(int i=0; i< my_str.size(); i++) {
		int type = my_str.at(i) - '0';
		if (my_str.at(i) == ' ')
		{
			if(!sp){
				sp=1;
				new_str.push_back(my_str.at(i));
			}
		} else if (is_special_chr(type)){
			new_str.push_back(my_str.at(i));
			sp=1;
		} else {
			new_str.push_back(my_str.at(i));
			sp=0;
		}
	}
	cout << new_str << endl;
}


#endif

#ifdef STR2

/* Reverse words in a given string
Given a string “I like this program very much”, return the string to “much very program this like I” in O(n) time and O(1) space complexity,
where n is the length of the input string.
Input:   “I like this program very much”
Output: “much very program this like I”
*/

void reverse_str(string *s, int start, int end)
{
	string temp;
	for (;start < end; start++, end--)
	{
		temp.push_back(s->at(start));
		s->at(start) = s->at(end);
		s->at(end) = temp.at(temp.size()-1);
	}
}

int main()
{

string my_str("I like this program very much");

reverse_str(&my_str,0,my_str.size()-1); // first reverse it blindly

int start=0, i=0;

for (i=0; i < my_str.size(); i++)
{
	if (my_str.at(i) == ' ')
	{
		reverse_str(&my_str, start, i-1);
		start=i+1;
	}
}
cout << my_str << endl;
}

#endif

#ifdef STR3

/*
 * Given two strings, determine minimum number of operations (insert, del, substitute) to change 1 string to other
 *
 * */

int min_of_3(int a, int b, int c)
{
	if (a<b)
		return (a<c?a:c);
	else
		return (b<c?b:c);

}

int main()
{
	string s1("google");
	string s2("alphabet");
	int dp[s1.size()+1][s2.size()+1]={0};
	int temp=0;

	/* Initialize the first row and first column */
	while (temp <= s2.size() )
	{
		dp[0][temp]=temp;
		temp++;
	}
	temp=0;
	while (temp <= s1.size())
	{
		dp[temp][0]=temp;
		temp++;
	}
	
	/* C++ String compare returns 
	   0 if the string is same. 
 	   < 0 or > 0 if not same or if it matches but strings are not of equal lengths
	*/

	for (int i=1; i <= s1.size(); i++)
	{
		for (int j=1; j <= s2.size(); j++)
		{
			if(!s1.compare(i-1,1,s2,j-1,1)) // Is the chars are same.
				dp[i][j] = dp[i-1][j-1];
			else
				dp[i][j] = min_of_3(dp[i-1][j], dp[i-1][j-1], dp[i][j-1]) + 1;



 		}
	}

	cout << "MIN num of operations:" << dp[s1.size()][s2.size()] << endl;



}

#endif

#ifdef STR4
/*
Given two strings, find the length of the longest common substring.
For example, if the given strings are “HelloWorld” and Hello”, the output should be “Hello” (length = 5)
*/


int main()
{
	string s1("google");
	string s2("alphabet");
	string comm;
	int dp[s1.size()+1][s2.size()+1]={0};
	int max =0;



	for (int i=0; i < s1.size(); i++)
	{
		for (int j=0; j < s2.size(); j++)
		{
			if(!s1.compare(i,1,s2,j,1)){ //if the characters are same
				dp[i+1][j+1] = dp[i][j] + 1;

				if (max < dp[i+1][j+1]){
					max = dp[i+1][j+1];
					comm.clear();
					comm.replace(0, max, s1,i-max,max);
				}
			}

 		}
	}

	cout << "Longest common match is " << comm << endl;



}




#endif

#ifdef STR5
   /* Given N distinct integers, how many triples sum to exactly zero. */

int main()
{
	vector<int> v;
	= { 30, -40, -20, -10, 40, 0, 10, 5 };




}



#endif

#ifdef STR6
   /* Given N distinct integers, how many triples sum to exactly zero. */

 // Write an efficient function that takes stock_prices_yesterdayandreturnsthebestprofitIcouldhavemadefrom1purchaseand1saleof1Applestockyesterday.

int main()
{
   vector<int> v(6);
   v = { 10, 7, 5, 8, 11, 9 };

   int min=0, max=0, diff=0;
   min = v.at(0);

   for (int i=1; i < v.size() ; i++)
   {
	   if (min > v.at(i)) {
		   min = v.at(i);
		   max = 0;
	   }

	   if ( max < v.at(i) ) {
		   max = v.at(i);
	   }

	   if ( diff < (max - min))
		   diff = max - min;

	}

   if (max == v.at(1) && diff == 0 )  // Negative profit.
      diff = v.at()v.at(0);


   cout << "Buy at:" << min << "Sell at:" << max << "Profit is:" << diff << endl;
}

#endif

#ifdef STR5
/*
You have a list of integers, and for each index you want to find the product of every integer except the integer at that index
*/
int main()
{

	vector<int> foo(5);
	vector<int> doo(5);
	foo = { 1, 7, 3, 4, 6};
    int temp =1, i;

    for ( i=0 ; i < foo.size() ; i++)
    {
    	doo.at(i) = temp;
    	temp *= foo.at(i);

    }

    temp = foo.at(foo.size() -1);

    for ( i = (foo.size() - 2) ; i >= 0 ; i--)
    {
    	doo.at(i) *= temp;
    	temp *= foo.at(i);
    }

    for (i=0; i < doo.size() ; i++)
    {
    	cout << doo.at(i) << "  ";
    }
return 1;

}
#endif

#ifdef CAKE4

// CAKE 4

int main()
{

 /* Sorted list of meetings */

	vector < vector<int> > time { {0,1}, {1,2},  {1,5}, {1,10}, {2,3}, {2,6}, {3,5}, {4,8}, {7,9}, {9,10}, {10,12} , {0,0}	};
	int i;

    for ( i=0 ; i< time.size() -1; )
    {
    	if ( (time[i][1] > time[i+1][1]) || (time[i][1] >= time[i+1][0])  )
    	{  // merge now
    		cout << "merging (" << time[i][0] << " , " << time[i][1] << ")" << "(" << time[i+1][0] << " , " << time[i+1][1] << ")" << endl;
    		time[i+1][0] = time[i][0];
    		time[i+1][1] = (time[i][1] > time[i+1][1]) ? time[i][1] : time[i+1][1];
    		i++;
    	} else {
    		//cannot merge . So print it.
    		cout << "..(" << time[i][0] << " , " << time[i][1] << ")" << endl;
    	}
    }

    cout << "(" << time[ time.size()-1][0] << " , " << time[ time.size()-1][1] << ")" << endl;

    return 1;

}


#endif


#ifdef CAKE6

/* Find the overlapping rectangle */

class rectangle {
public:
	int x1;
	int y1;
	int h;   //height
	int w;   //width
};

 int main () {
	 class rectangle r1, r2, r3;

	 r1.x1 = 1;
     r1.y1 = 5;
     r1.h = 4;
     r1.w = 10;

     r2.x1 = 9;
     r2.y1 = 6;
     r2.h = 10;
     r2.w = 4;

     // find X axis overlap

     if (((r1.x1 < r2.x1) && (r2.x1 < (r1.x1+r1.w)))  ) // overlap on the right
     {
    	 r3.x1 = r2.x1;
     } else if (( ( r1.x1 < (r2.x1+r2.w) ) && ( (r2.x1+r2.w)) < (r1.x1+r1.w) )) //overlap on the left
     {
    	 r3.x1 = r1.x1;
     }

#endif

#ifdef UNORDERDERED_MAP_TEMP

     vector<int> numbers = {2, 7, 11, 15};
     int target = 9;

     unordered_map<int, int>  mymap;
     vector<int> result = {0};

             if ( numbers.size() == 1)
             	return 0;

             mymap.insert({target - numbers[0], 0} );

             for ( int i=1; i < numbers.size() ; i++)
             {
                 std::unordered_map<int, int>::const_iterator got = mymap.find(numbers.at(i));

                 if ( got != mymap.end())
                 {
                     result[0] = got->second + 1;
                     result[1] = i+1;
                    cout << got->second + 1 << "and" << i+1 <<endl;
                 }else {
                     int diff = target - numbers.at(i);
                     mymap.insert({diff, i});
                 }
             }
             return 0;

#endif
#if 0
     int main()
     {
    	 	 string a="1010";
    	 	 string b="1011";
    	     int i, j;

    	 	 if ( a.size()==0 && b.size() ==0 )
    	            return 0;

    	         int carry=0;
    	         string r="";
    	         for ( i=a.size()-1, j=b.size()-1; (( i>=0 && j>=0) == 1) ; i--,j-- )
    	         {
    	              if ( (a[i] - '0' ) ){
    	                  if ( b[j] - '0' ){
    	                    if ( carry )
    	                        r.insert(0,"1");
    	                    else {
    	                        r.insert(0,"0");
    	                        carry = 1;
    	                    }
    	                  } else {
    	                      if ( carry )
    	                        r.insert(0,"0");
    	                      else
    	                         r.insert(0,"1");
    	                  }
    	              } else {
    	                  if ( b[j] - '0' ){
    	                    if ( carry )
    	                        r.insert(0,"0");
    	                    else
    	                        r.insert(0,"1");
    	                  } else {
    	                      if ( carry )
    	                        r.insert(0,"1");
    	                         else
    	                         r.insert(0,"0");
    	                  }
    	              }

    	         }

    	         if ( i < 0){
    	             while ( j >= 0 ) {
    	                 if ( b[j] - '0') {
    	                     if ( carry )
    	                        r.insert(0, "0");
    	                     else
    	                       r.insert(0, "1");
    	                 } else {
    	                      if ( carry ) {
    	                        r.insert(0, "1");
    	                        carry = 0;
    	                     } else
    	                       r.insert(0, "0");
    	                 }
    	                 j--;
    	            }
    	         }

    	          if ( j < 0){
    	             while ( i >= 0 ) {
    	                 if ( a[i] - '0') {
    	                     if ( carry )
    	                        r.insert(0, "0");
    	                     else
    	                       r.insert(0, "1");
    	                 } else {
    	                      if ( carry ) {
    	                        r.insert(0, "1");
    	                        carry = 0;
    	                     } else
    	                       r.insert(0, "0");
    	                 }
    	                 i--;
    	            }
    	         }

    	         if ( carry )
    	             r.insert(0, "1");

    	         if ( r.size() == 0 )
    	             r.insert(0, "0");

    	         cout << "Sum is " << r << endl;


     }



     int main() {

    	vector<int> nums = { 1,2};
    	vector<vector<char>> wds { {'A','B','C','E'} , { 'S','F','C','S'} , { 'A','D','E','E'} };

    	cout << wds.size() << wds [2][2] << endl;
    	         int curr, next;
    	         int val;

    	         if ( nums.size() < 2 )
    	             return nums.size();

    	         for ( curr=0, next=1 ; next < nums.size() ;   )
    	         {
    	             if ( nums.at(curr) == nums.at(next) )
    	                 next++;
    	             else {
    	                 if ( curr+1 != next )
    	                 {
    	                     nums.at(++curr) = nums.at(next);
    	                     ++next;
    	                 } else {
    	                     ++curr;
    	                     ++next;
    	                 }
    	             }
    	         }

    	         if ( !curr )
    	             cout<< "1";

    	         if ( curr == nums.size() )
    	             cout << curr;
    	         else
    	             cout << curr+1;

     }



     bool find_nearest( vector<vector<char>>& board, int i, int j, int k)
     	    {

    	 string word = "ABCCED";

     	        if ( k == word.size())
     	            return 1;

     	        int ret=0;

     	        if ( word[k] == board[i][j-1] )
     	            ret = find_nearest( board, i , j-1 , k++ );

     	        if ( !ret && j+1 < board[i].size() && word[k] == board[i][j+1] )
     	            ret = find_nearest(board, i, j+1, k++);

     	        if (!ret &&  i && j < board[i-1].size() && word[k] == board[i-1][j] )
     	            ret = find_nearest(board, i-1, j, k++);

     	        if (!ret &&  i+1 < board.size() && j < board[i+1].size() && word[k] == board[i+1][j] )
     	            ret = find_nearest(board, i+1, j, k++);

     	         if ( ret || k==1 )
     	            return 1;
     	        else
     	        	return 0;


     	    }

int main()
{

	    	vector<vector<char>> board { {'A','B','C','E'} , { 'S','F','C','S'} , { 'A','D','E','E'} };
	    	string word = "ABCCED";
	        int num = board.size();
	        int k=0;
	        int start=0;

	        if ( !num || !word.size())
	            return 0;

	        for ( int i=0 ; i<num ; i++ )
	        {
	            for ( int j=0; j<board[i].size() ; j++ )
	            {
	                if ( board[i][j] == word[k])
	                {
	                    int found=0;
	                    start=1;
	                    if ( ++k < word.size() )
	                        found = find_nearest( board, i, j , k+1);
	                    else
	                        return 1;

	                    if ( found)
	                        return 1;
	                }

	            }
	        }

	        return 0;
	    }

#endif
#if LONGEST_NON_REPEAT
#include <iostream>
#include <cstdint>
#include <cstring>
#include <unordered_map>
#include <string>

using namespace std;
#define MAX_ALPHA 26
/*
Find the longest substring without repeating characters in the given input:

Given a string, find the length of the longest substring without repeating characters.
For example, the longest substring without repeating letters for “abcabcbb” is “abc”, which the length is 3.
For “bbbbb” the longest substring is “b”, with the length of 1.
*/


int main()
{

	string s("sdfklsdnlkjfbdsfkbndkljsfnbksldfnbklsjjioasdfnkldsfnlasdkfjlasdn");
	//string s("abcdefgh");
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

	cout << "MAx len is " << maxlen <<  endl;

}
#endif

#if 0

bool get_output ( )
{
	int m = 5;
	int n = 5;

		return (m==n);
}
int main()
{
	vector<int> nums1 = { 0,0,0,0,0 };
	vector<int> nums2 = { 1,2,3,4,5 };
    int val = 0;
	int ret = get_output();
	ret =  ( val ? 1 : 0 );
	cout << ret << endl;

}
#endif

#ifdef AMZN1

//Write a function that given 2 strings, determines if they are disjoint.

#endif

#ifdef STROBO
bool is_Strobogrammatic( char c ) {
    if ( c == '1' || c == '6' || c == '8' || c == '9' )
    return 1;

    return 0;
}

char get_inverted( char c )
{
    if ( c == '1' || c == '8' )
        return c;
    else if ( c == '6' )
        return '9';
    else if ( c == '9' )
        return '6';

    return c;

}

int main() {
    int i = 0 ;
    string strnum;
    string num="818";

    if ( num.size() == 0 )
        return 0;

    while ( i < num.size() )
    {
        if ( is_Strobogrammatic( num[i] ) )
        {
            strnum.push_back ( get_inverted( num[i] ) );
        } else {
        	cout << " IS NOT " << endl;
        }
        i++;
    }
    strnum[i] == '\0';


    if ( num.compare( strnum ) == 0 )
       cout << " IT IS " << endl;

    cout << strnum << endl;
    cout << num << endl;

    cout << " IS NOT " << endl;
    return 1;

}
#endif


#ifdef ISOMORPHIC
/*test if a pair of strings are Isomorphic
Two strings are isomorphic if the characters in s can be replaced to get t.

For example,"egg" and "add" are isomorphic, "foo" and "bar" are not.  */

int main()
{
	string str1, str2;
	std::cin >> str1 >> str2 ;
	unordered_map< char, char> mymap;
	const char * c = str1.c_str();

	if ( str1.size() != str2.size() )
	{
		cout << " NO";
		return 0;
	}

	for ( int i=0; i < str1.size() ; i++ )
	{
		if ( mymap.find( c[i] ) != mymap.end() )
		{
			if ( mymap[str1.at(i)] != str2[i] )
			{
				cout << " NO";
				return 0;
			}
		} else {
			mymap[str1.at(i)] = str2[i];
		}
	}
	cout << "Yes. The inputs are ISOmorpthic" << endl;
	return 1;
}
#endif
