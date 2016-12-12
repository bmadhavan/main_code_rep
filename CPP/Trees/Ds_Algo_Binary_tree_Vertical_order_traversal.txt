Binary Tree Vertical Order Traversal

Given a binary tree, return the vertical order traversal of its nodes' values. (ie, from top to bottom, column by column).
If two nodes are in the same row and column, the order should be from left to right.

Given binary tree [3,9,20,null,null,15,7],
   3
  /\
 /  \
 9  20
    /\
   /  \
  15   7
return its vertical order traversal as:
[
  [9],
  [3,15],
  [20],
  [7]
]


    void BFS( TreeNode* root, map<int, vector<int>> &mymap  ) { 
        if ( !root ) return; 
        queue<TreeNode*> q;
        vector<int> num;
        
        q.push(root); 
        num.push_back(0);
        
        TreeNode* t;
        int i=0;
        
        while ( !q.empty() ) { 
            t=q.front();
            q.pop();
            mymap[num[i]].push_back( (t->val) );
            if ( t->left ) { q.push(t->left); num.push_back(num[i]-1); }
            if ( t->right ) { q.push(t->right); num.push_back(num[i]+1); }
            i++;
        }
        return;
    }


    vector<vector<int>> verticalOrder(TreeNode* root) {
       vector<vector<int>> result;
       map<int, vector<int>> mymap;
       if ( !root ) return result;
       int j=0;
       BFS( root, mymap);
       for ( auto i : mymap )
           result.push_back( i.second );

       return result;
           
    }
