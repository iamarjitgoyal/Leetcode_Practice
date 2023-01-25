class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty()) return false;
        int rows = matrix.size();
        int cols = matrix[0].size();
        for(int i = 0 ; i < rows ; i++){
            int left = 0, right = cols-1;
            while(left <= right){
                int mid = left + (right-left)/2;
                if(matrix[i][mid] == target) return true;
                else if(matrix[i][mid] < target) left = mid+1;
                else right = mid-1;
            }
        }
        return false;
    }
};
