Print all the anagrams of a given word. 



void PrintAnagrams( string s, int i ) {
	int j = 0 ;
	if ( i == s.length() -1 ) cout << s << endl;
	else {
		for ( j = i; j < s.length() ; j++ ) {
			swap(s[i], s[j]);
			PrintAnagrams( s, i+1 );
			std:swap(s[i], s[j]);
		}
	}
}

int main(){
	string str="abc";  // test string
	PrintAnagrams(str, 0 );
}