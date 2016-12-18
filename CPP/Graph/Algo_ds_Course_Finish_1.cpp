Course Schedule


There are a total of n courses you have to take, labeled from 0 to n - 1.
Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]
Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

For example:

2, [[1,0]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0. So it is possible.

2, [[1,0],[0,1]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.

Note:
The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.

class Solution {
    class graph { 
private:
        int num_courses;
        vector<vector<int>> adj;
public:
        graph( int x ) : num_courses(x), adj(num_courses, vector<int> {} ) { }
        
        void AddEntry( int x, int y ){
            adj[x].push_back(y); 
        }
    
        bool HasLoop ( int index , vector<int> &visited ) { 
            visited[index] = 1; // we are currently visting this. 
            int k;
            for ( k=0 ; k < adj[index].size() ; k++ ) { 
                 if ( visited[ adj[index][k] ] == 1 )  return true; // 
                 else if ( visited[ adj[index][k] ] == 2 ) continue; 
                 else { // if not visited. Go and visit.  
                    if ( HasLoop( adj[index][k], visited ) == true )
                        return true;
                }
            }
            visited[index] = 2; 
            return false;
        }
    };
public:
    
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        graph g(numCourses);
        vector<int> visited(numCourses, 0); // 0 not visited, 1 current, 2 visited
        if ( numCourses <= 1 ) return 1;
        
        for ( int i=0; i< prerequisites.size() ; i++ )
            g.AddEntry(prerequisites[i].first, prerequisites[i].second );
            
        for ( int i=0 ; i < numCourses ; i++ ) { 
            if ( visited[i] == 0 ) {
                if ( g.HasLoop( i , visited ) == true )
                    return false; 
            }
        }
        return true;
    }
};