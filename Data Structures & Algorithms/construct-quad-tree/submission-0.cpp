/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
      return makeTree(grid,0,0,1);
        
    }

    Node* makeTree(vector<vector<int>>& grid, int r, int c, int phase){
        Node* root = new Node();
        if(isSame(grid,r,c,phase)){
            root->val = grid[r][c];
            root->isLeaf = true;
        }
        else{
        phase = phase * 2;
        int f = grid.size() / phase;
            root->topLeft = makeTree(grid,r,c,phase);
            root->topRight = makeTree(grid,r,c + f,phase);
            root->bottomLeft = makeTree(grid,r + f,c,phase);
            root->bottomRight = makeTree(grid,r + f,c + f,phase);
        }
        return root;
    }
    bool isSame(vector<vector<int>>& grid, int r, int c, int phase){
        bool key = grid[r][c];
        int f = grid.size() / phase;
        for(int i = 0; i < f; i++){
            for(int j = 0; j < f; j++){
                if(grid[r + i][c + j] != key) return false;
            }
        }
        return true;
    }
};