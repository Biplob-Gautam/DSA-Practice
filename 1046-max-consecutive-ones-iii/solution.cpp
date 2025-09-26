class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0, r = 0;  
        int maxLen = 0;
        int oneCount=0;

        while (r < nums.size()) {
            if(nums[r]==1)oneCount++;
            while ((r - l + 1) - oneCount > k) {
                if(nums[l]==1)oneCount--;
                l++;
            }
            maxLen = max(maxLen, r - l + 1);
            r++;
        }
        return maxLen;
    }
};
