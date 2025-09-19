class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int lb=lower_bound(nums.begin(),nums.end(),0) - nums.begin();
        int ub=upper_bound(nums.begin(),nums.end(),0) - nums.begin();

        int neg=lb;
        int pos=nums.size()-ub;

        return max(pos,neg);
    }
};
