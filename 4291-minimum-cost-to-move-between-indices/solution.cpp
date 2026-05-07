class Solution {
public:
    vector<int> minCost(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();

        vector<int> closest(n);
        for (int i = 0; i < n; i++) {
            if (i == 0) closest[i] = 1;
            else if (i == n-1) closest[i] = n-2;
            else {
                int left = nums[i] - nums[i-1];
                int right = nums[i+1] - nums[i];
                if (left <= right) closest[i] = i-1;
                else closest[i] = i+1;
            }
        }

        vector<long long> pref(n, 0);
        for (int i = 1; i < n; i++) {
            int normal = nums[i] - nums[i-1];
            int special = (closest[i-1] == i ? 1 : INT_MAX);
            pref[i] = pref[i-1] + min(normal, special);
        }
        
        vector<long long> prefBack(n, 0);
        for (int i = n-2; i >= 0; i--) {
            int normal = nums[i+1] - nums[i];
            int special = (closest[i+1] == i ? 1 : INT_MAX);
            prefBack[i] = prefBack[i+1] + min(normal, special);
        }

        vector<int> res;

        for (auto &q : queries) {
            int l = q[0];
            int r = q[1];

            if (l < r)
                res.push_back(pref[r] - pref[l]);
            else
                res.push_back(prefBack[r] - prefBack[l]);
        }

        return res;
    }
};
