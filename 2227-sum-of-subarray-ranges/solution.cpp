class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long sum=0, res=0;
        int n=nums.size();
        for(int i=0; i<n; i++){
            int minVal=nums[i], maxVal=nums[i];
            for(int j=i; j<n; j++){
                minVal = min(minVal,nums[j]);
                maxVal = max(maxVal,nums[j]);
                res = maxVal-minVal;
                sum += res;
            }
        }
        return sum;
    }
};
