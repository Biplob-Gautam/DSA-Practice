class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        //Prefix Sum method works even when it is now a binary array

        // unordered_map<int,int> hash;
        // hash[0]=1;

        // int prefix=0,count=0;
        // for(int &x : nums){
        //     prefix +=x;

        //     if(hash.find(prefix - goal) != hash.end()){
        //         count += hash[prefix- goal];
        //     }

        //     hash[prefix]++;
        // }
        // return count;

        //sliding window method
        return res(nums,goal)-res(nums,goal-1);
    }

private:

    int res(vector<int>nums, int goal){
        if(goal<0) return 0;
        int l=0,r=0,sum=0,count=0,n=nums.size();
        while(r<n){
            sum+=nums[r];
            while(l<=r && sum>goal){
                sum-=nums[l];
                l++;
            }
            count+=(r-l+1);
            r++;
        }
        return count;
    }
};
