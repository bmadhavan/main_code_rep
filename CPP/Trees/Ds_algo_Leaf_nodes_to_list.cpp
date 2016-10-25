/* Take all leaf nodes of a binary tree in order, and put them into a linked list. */

struct TreeNode { 
	int value;
	TreeNode *left;
	TreeNode *right;
};

struct ListNode { 
	int value; 
	ListNode *next;
	ListNode( int n) : value(n) , next(nullptr) {}
};


ListNode* GetListOfLeaf( struct TreeNode *t )
{

 if ( !t )
 	return; 

 stack<TreeNode*> st;
 TreeNode* temp;
 ListNode* head = new ListNode(0);
 ListNode* curr = head;  

 while ( t || !st.empty() )
 {
 	if ( t ) { 
 		st.push( t ); 
 		t = t->left;
 	} else { 
 		temp = st.top();
 		st.pop();
 		if ( !temp->left && !temp->right )
 		{
 			curr->next = new ListNode( temp->value );
 			curr=curr->next;
 		} else { 
 			t = temp->right;
 		}
 	}
 }
 curr = head->next;
 free(head);
 return ( curr );

}
