class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low=0, high=nums.size()-1;
        int res = Bsearch(nums,target,low,high);
        return res;
    }

private:

    int Bsearch(vector<int> &nums, int target, int low, int high){
        if(low>high) return low;
        int mid=(low+high)/2;
        if(nums[mid]==target) return mid;
        else if(nums[mid]<target) return Bsearch(nums,target,mid+1,high);
        else return Bsearch(nums,target,low,mid-1);
    }
};
