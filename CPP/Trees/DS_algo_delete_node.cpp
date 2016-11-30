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


TreeNode* deleteNode(TreeNode* root, int key) {
        if ( !root ) return nullptr; 
        TreeNode* temp=nullptr;
        
        if ( root->val == key ){ 
            if ( root->left == root->right ) { free(root); return nullptr; }
            if ( root->left == nullptr || root->right == nullptr ) { 
                temp = root->left ? root->left : root->right;
                free(root);
                return temp; }
                
            /* The node has both left and right */
            temp = root;
            temp=temp->right;
            while (temp->left)
                temp=temp->left;
            // Now delete this node
            key = temp->val;
        }
        
        if ( root->val < key ) 
            root->right = deleteNode(root->right, key);
        else
            root->left = deleteNode(root->left, key);
        
        if ( temp ) root->val=key;
        
        return root;
    }