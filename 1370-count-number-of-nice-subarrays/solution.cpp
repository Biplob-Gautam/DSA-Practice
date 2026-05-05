class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        // converting nums such that even=0 odd=1 now problem becomes count subarray with sum = k  
        for(auto &x : nums){
            if(x%2==0)x=0;
            else x=1;
        }
        return res(nums,k)-res(nums,k-1);
    }

private:
    int res(vector<int> nums, int k){
        if(k<0)return 0;
        int l=0,r=0,count=0,sum=0,n=nums.size();
        for(int i=0; i<n; i++){
            sum+=nums[r];
            while(l<=r && sum>k){
                sum-=nums[l];
                l++;
            }
            count+=(r-l+1);
            r++;
        }
        return count;
    }
};
