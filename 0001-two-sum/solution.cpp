class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //tc = n to n^2 cuz worst case unordered map go to n, sc = n
        //if used normal map then tc = nlog(n)

        unordered_map<int,int> mpp;
        for(int i=0;i<nums.size(); i++){
            int moreNeeded = target - nums[i];
            if(mpp.find(moreNeeded) != mpp.end()) return {i,mpp[moreNeeded]};
            mpp[nums[i]] = i;
        }
        return {-1,-1};


    }
};
