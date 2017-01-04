/* 
Given a root node reference of a BST and a key, delete the node with the given key in the BST. 
Return the root node reference (possibly updated) of the BST.

Basically, the deletion can be divided into two stages:

Search for a node to remove.
If the node is found, delete the node.
Note: Time complexity should be O(height of tree).

My Solution: 
Search for the node using value and move either right or left. 
Once you find the node, handle 3 cases. 
1) Node's both child are null. 
2) Node's one child is null. 
3) Node both child are present. 
For case 3, find the next highest node's value to be used. Change the current node value to the next highest and delete that node. 
*/

TreeNode* deleteNode(TreeNode* root, int key) {
        if ( !root ) return nullptr; 
        TreeNode* newroot=nullptr;
        
        /* Handle all 3 cases here */
        if ( root->val == key ){ 
            /* leaf node */ 
            if ( root->left == root->right ) { delete root; return nullptr; }
            /* No right or left node. */ 
            if ( root->left == nullptr || root->right == nullptr ) { 
                newroot = root->left ? root->left : root->right;
                delete root;
                return newroot;
            }
            /* Node has both left and right. Find the next minimum node */
            newroot = root->right;
            while (newroot->left) newroot=newroot->left;
            // Now delete this node
            key = newroot->val;
        }
        
        if ( root->val < key ) 
            root->right = deleteNode(root->right, key);
        else
            root->left = deleteNode(root->left, key);
        
        if ( newroot ) root->val=key;
        
        return root;
    }
