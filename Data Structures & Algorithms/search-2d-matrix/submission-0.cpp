class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int left = 0;
        int right = matrix.size() * matrix[0].size() - 1;
        int coll = matrix[0].size();
        while(left <= right){
            int mid = (left + right) / 2;
            int mrow = mid / coll;
            int mcol = mid % coll;
            if(matrix[mrow][mcol] == target){
                return true;
            }
            else if( matrix[mrow][mcol] < target){
                left = mid + 1;
            }
            else right = mid - 1;
        }
        return false;
    }
};
