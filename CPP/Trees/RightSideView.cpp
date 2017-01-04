/*
Binary Tree Right Side View
Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

For example:
Given the following binary tree,
   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
You should return [1, 3, 4].

*/


    vector<int> rightSideView(TreeNode* root) {
        vector<int> result; 
        if ( !root ) return result;
            
        queue<TreeNode*> bfs;
        bfs.push(root);
        bfs.push(nullptr); 
        
       while ( !bfs.empty() ) { 
            TreeNode* curr = bfs.front();
            bfs.pop();
            
            if ( curr->left ) bfs.push( curr->left );
            if ( curr->right ) bfs.push( curr->right );
            if ( !bfs.empty() && bfs.front() == nullptr ){
                result.push_back( curr->val );
                bfs.pop();
                if ( !bfs.empty() ) bfs.push(nullptr);
            }
       }
       return result;
    }


