Given a complete binary tree, count the number of nodes.

Definition of a complete binary tree from Wikipedia:
In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

Solution: 
Option 1: Binary search in the last leaf nodes to find the first leaf which is missing. 
Options 2: (Below) Simply recurse to the left most node and right most node and return the count if the heights are same. 
Using the property of complete binary tree this will return the total number of nodes in the last level.   


  int countNodes(TreeNode* root) {
    TreeNode* t = root; 
    int lh=0, rh=0;     
    if ( !root ) return 0;
    
    while ( t ) {
        t = t->left; lh++; 
    }
    t = root; 
    while ( t ) {
        t = t->right; rh++; 
    }
    
    if ( lh == rh )
        return ( pow(2,lh)-1 );
    
    return ( countNodes(root->left) + countNodes(root->right) +1 );
        
    }