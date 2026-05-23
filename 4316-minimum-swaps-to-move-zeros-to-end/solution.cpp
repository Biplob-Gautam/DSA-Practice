class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int i=0,j=nums.size()-1,n=nums.size();

        int count=0;
        while(i<j){
            while(i<j && nums[j]==0)j--;
            if(nums[i]==0 && nums[j]!=0){
                swap(nums,i,j);
                count++;
                j--;
            }
            i++;
        }
        return count;
    }

private:
    void swap(vector<int>& nums, int i,int j){
        int temp=nums[i];
        nums[i]=nums[j];
        nums[j]=temp;
    }
};
