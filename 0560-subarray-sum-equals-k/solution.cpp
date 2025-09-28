class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        freq[0] = 1;
        int prefix = 0, count = 0;

        for (int num : nums) {
            prefix += num;
            
            if (freq.find(prefix - k) != freq.end()) {
                count += freq[prefix - k];
            }
            freq[prefix]++;
        }
        return count;
    }
};
