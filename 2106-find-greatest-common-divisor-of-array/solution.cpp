class Solution {
public:
    int findGCD(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n=nums.size();
        int mn=nums[0], mx=nums[n-1];
        // int i=mn;

        // while(i!=1){
        //     if(mn%i==0 && mx%i==0) return i;
        //     i--;
        // }
        // return i;

        return __gcd(mn,mx);
    }
};
