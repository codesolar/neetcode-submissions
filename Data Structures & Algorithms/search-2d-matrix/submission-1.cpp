class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0, r = matrix.size() - 1;
        int mid = -1;
        while(l <= r){
            mid = l + (r - l)/2;
            if(matrix[mid][0] == target){
                return true;
            }
            if(matrix[mid][0] > target){
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        int row = r;
        if(row == -1) return false;
        l = 0;
        r = matrix[0].size() - 1;
        while(l <= r){
            mid = l + (r - l)/2;
            if(matrix[row][mid] == target) {
                return true;
            }
            if(matrix[row][mid] < target){
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        return false;
    }
};
