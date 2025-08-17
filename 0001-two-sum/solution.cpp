class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;   // stores value -> index
        int n = nums.size();

        for(int i = 0; i < n; i++){
            // check if target - nums[i] already exists in map
            if(mp.find(target - nums[i]) != mp.end()){
                // if found, return indices {stored index, current index}
                return {mp[target - nums[i]], i};
            }

            // otherwise store this element in the map
            mp[nums[i]] = i;
        }

        // in case no solution (though problem guarantees one)
        return {};
    }
};

