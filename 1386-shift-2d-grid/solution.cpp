class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int rows=grid.size(), cols=grid[0].size();
        vector<int> nums = Give1d(grid);
        vector<int> ans(nums.size());
        int i=0;
        k = k%nums.size();
        while(k!=nums.size()){
            ans[k]=nums[i];
            k++;
            i++;
        }

        k=0;
        while(i!=nums.size()){
            ans[k]=nums[i];
            k++;
            i++;
        }

        grid = Give2d(ans,rows,cols);
        return grid;
    }



private:
    vector<int> Give1d(vector<vector<int>> &matrix){
        vector<int> ans;

        for(auto &row: matrix){
            for(int val: row){
                ans.push_back(val);
            }
        }
        return ans;
    }


    vector<vector<int>> Give2d(vector<int> &nums, int rows, int cols){
        vector<vector<int>> matrix(rows, vector<int>(cols));

        int k=0; 

        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                matrix[i][j] = nums[k++];
            }
        }

        return matrix;
    }
};
