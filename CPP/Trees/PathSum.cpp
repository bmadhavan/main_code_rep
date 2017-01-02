/*
Path Sum I

Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.



Solution: Do DFS. Decrement sum as you go to the next level. Check if at any point sum ==0 with no left AND no right node.  

*/

 bool hasPathSum(TreeNode* root, int sum) {
        
        if ( !root ) return false;
        sum = sum - root->val; 
        if ( !root->left && !root->right && !sum ) return true; 
        if ( hasPathSum(root->left, sum) || hasPathSum(root->right, sum) ) return true;
        return false; 
    }


/*
Path Sum II

Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return
[
   [5,4,11,2],
   [5,8,4,5]
]

*/


private:
    void pathSumHelper(TreeNode* root, int sum, vector<int> &curr, vector<vector<int>> &result ){
        if ( !root ) return;
        curr.push_back(root->val);
        sum = sum - root->val; 
        if ( !root->left && !root->right && !sum ) { result.push_back(curr); curr.resize(curr.size()-1); return; }
        pathSumHelper(root->left, sum, curr, result);
        pathSumHelper(root->right, sum, curr, result);
        curr.resize(curr.size()-1);
    }
public:    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> path;
        vector<vector<int>> result; 
        if ( !root ) return result;
        pathSumHelper( root, sum, path, result);
        return result;
  
    }