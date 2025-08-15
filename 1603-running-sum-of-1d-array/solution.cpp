class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
     for(int i=0; i<nums.size()-1; i++){
        nums[i+1]=nums[i]+nums[i+1];
     }   
     return nums;
    }
};
