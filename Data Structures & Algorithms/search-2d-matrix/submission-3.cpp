class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int top = 0, bottom = matrix.size() - 1;
        int midRow, midCol;

        while(top <= bottom){
            midRow = (top + bottom)/2;

            if(target > matrix[midRow].back()){
                top = midRow + 1;
            }
            else if(target < matrix[midRow].front()){
                bottom = midRow - 1;
            }
            else{
                int left = 0, right = matrix[midRow].size() - 1;
                while(left <= right){
                    midCol = (left + right)/2;
                    if(target > matrix[midRow][midCol])
                        left = midCol + 1;
                    else if(target < matrix[midRow][midCol])
                        right = midCol - 1;
                    else
                        return true;
                }
                return false;
            }
        }
        return false;
    }
};
