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
    Node* func(vector<vector<int>> &grid, int l, int r, int t, int d){
        bool x = true;
        int first = grid[t][l];
        for(int i = t; i <= d; i ++){
            for(int j = l; j <= r; j ++){
                if(first != grid[i][j]){
                    x = false;
                    break;
                }
            }
            if(x == false) break;
        }
        if(x){
            return new Node(first, 1);
        }
        else{
            int mid_col = (int)(l + r)/2;
            int mid_row = (int)(t + d)/2;
            auto n1 = func(grid, l, mid_col, t, mid_row);
            auto n2 = func(grid, mid_col + 1, r, t, mid_row);
            auto n3 = func(grid, l, mid_col, mid_row + 1, d);
            auto n4 = func(grid, mid_col + 1, r, mid_row + 1, d);
            auto node = new Node(1, 0, n1, n2, n3, n4);
            return node;
        }
        return NULL;
    }
    Node* construct(vector<vector<int>>& grid) {
       return func(grid, 0, grid[0].size() - 1, 0, grid.size() - 1);
    }
};