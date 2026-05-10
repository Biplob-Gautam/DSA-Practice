class Solution {
public:
    long long minArraySum(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);

        unordered_set<int> st(nums.begin(), nums.end());

        for(int x : nums){
            int best=x;
            for(int d=1; 1LL*d*d <=x; d++){
                if(x%d == 0){
                    int d1 =d; 
                    int d2 =x/d;

                    if(d1!= x && st.count(d1)) best = min(best,d1);
                    if(d2 != x && st.count(d2)) best = min(best,d2);
                } 
            }
            ans.push_back(best);
        }

        // for(int x: nums)cout<<x;

        long long res=0;
        for(int x : ans) res+=x;

        return res;
    }
};
