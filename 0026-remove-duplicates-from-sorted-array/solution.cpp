class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0,j=0;
        while(j<nums.size()){
            if(nums[i]==nums[j]) j++;
            else if(nums[i]!=nums[j]){
                nums[i+1] = nums[j];
                j++;
                i++;
            }
        }
        return i+1;
    }
};
