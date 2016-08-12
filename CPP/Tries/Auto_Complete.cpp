
//============================================================================
// Name        : Auto_complete.cpp
// Author      : bmadhava
// Version     : Jun 3, 2016
// Copyright   : Your copyright notice
// Description : Auto complete using Tries in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Auto_Complete.h"
using namespace std;

Node* Node::FindChild( char c )
{
	vector<Node*> v = GetChildren();

	for ( int i=0 ; i < v.size() ; i++ )
	{
		if ( (v.at(i))->GetMarker() && (v.at(i))->GetData() == c )
			return v.at(i);
	}
	return 0;
}


void Trie::AddWord( string s )
{
	int i=0;
	Node* tmp = root;

	while ( i < s.length() )
	{
		Node* c = tmp->FindChild( s.at(i) );

		if ( c == NULL )
		{
			Node *n = new Node( s.at(i) );
			tmp->AddChild( n );
			tmp = n;
		} else {
			tmp = c;
		}
		i++;
	}
}

bool Trie::SearchWord ( string s )
{
	int i=0;
	Node * tmp = root;

	if ( tmp == 0 )
		return 0;

	while ( i < s.length() )
	{
		Node* c = tmp->FindChild( s.at(i) );
		if ( c )
			tmp =c;
		else
			return 0;
		i++;
	}
	return 1;

}

int main() {
	cout << "!!!Hello Trie !!!" << endl;

	Trie* ac = new Trie;
    ac->AddWord("California");
    ac->AddWord("Colarado");
    ac->AddWord("Alaska");
    ac->AddWord("Arizona");

    if ( ac->SearchWord("Barcelona") )
    	cout << "Found Barcelona" << endl;
    else
    	cout << "Barcelona not found" << endl;

    if ( ac->SearchWord("California") )
       	cout << "California found" << endl;
    else
       	cout << "California not found" << endl;

}
