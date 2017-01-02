
/* 
Symmetric Tree

Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following [1,2,2,null,3,null,3] is not:
    1
   / \
  2   2
   \   \
   3    3
   
   */
   
    bool helper ( TreeNode* p, TreeNode* q ) {
        if ( !p && !q ) return true;
        if ( !p != !q ||  p->val != q->val )  return false;
        return ( helper(p->left, q->right) && helper(p->right, q->left) );
     }
    
    bool isSymmetric(TreeNode* root) {
       if ( !root ) return 1; 
       return ( helper( root->left , root->right ) );
    }
