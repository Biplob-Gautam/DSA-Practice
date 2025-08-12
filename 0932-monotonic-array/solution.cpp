class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        vector<int>inc(nums);
        vector<int>dec(nums);
        int n=nums.size();
       sort(inc.begin(),inc.end());
       sort(dec.begin(),dec.end(),greater<int>()); 
      if(inc==nums)return true;
      else if(dec==nums)return true;
       else return false;
    }
};
