class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return (res(nums,k) - res(nums,k-1));
    }

private:
    int res(vector<int>&nums, int k){
        int count=0,n=nums.size();
        int l=0,r=0;
        unordered_map<int,int>mpp;
        
        while(r<n){
            mpp[nums[r]]++;
            while(mpp.size()>k){
                mpp[nums[l]]--;
                if(mpp[nums[l]]==0)mpp.erase(nums[l]);
                l++;
            }
            count+=(r-l+1);
            r++;
        }
        return count;
    }
};
