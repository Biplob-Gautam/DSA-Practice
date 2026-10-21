class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size(); 
        k=k%n;
        vector<int> res;
        for(int j=n-k; j<n; j++){
            res.push_back(nums[j]);
        }
        for(int i=0; i<n-k; i++){
            res.push_back(nums[i]);
        }

        for(int i=0; i<n; i++){
            nums[i]=res[i];
        }
    }
};