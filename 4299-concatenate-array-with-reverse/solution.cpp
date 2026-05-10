class Solution {
public:
    vector<int> concatWithReverse(vector<int>& nums) {
        int n = nums.size();

        vector<int> ans(2*n);

        for(int i=0; i<n; i++){
            ans[i]=nums[i];
        }

        int index = (2*n)-1;
        for(int i=0; i<n; i++){
            ans[index]=nums[i];
            index--;
        }

        return ans;
    }
};
