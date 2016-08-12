/*
 * Auto_Complete.h
 *
 *  Created on: Jun 3, 2016
 *      Author: bmadhava
 */

#ifndef AUTO_COMPLETE_H_
#define AUTO_COMPLETE_H_

#include <vector>
using namespace std;

class Node {
public:
	Node() { content = ' ' ; marker = false; }
	Node ( char c )
	{
		content = c ;
		marker = true;
	}

	~Node() {}

	void SetData( char c ) { content = c; }
	char GetData() { return content; }

	void SetMarker( bool m ) { marker = m; }
	bool GetMarker() { return marker; }

	Node* FindChild(char c);
	void AddChild( Node* n) { children.push_back(n); }
	vector<Node*>GetChildren(){ return children; }

private:
	char content;
	bool marker;
	vector<Node*> children;
};


class Trie {
public:
   Trie() { root = new Node(); }
   ~Trie();
   void AddWord( string s );
   bool SearchWord( string s );
   void DeleteWord( string s );

private:
	Node* root;

};

#endif /* AUTO_COMPLETE_H_ */
