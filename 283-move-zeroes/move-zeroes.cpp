class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // int n=nums.size();
        // int k=0;

        // for(int i=0; i<n; i++){
        //     if(nums[i]!=0){
        //         nums[k]=nums[i];
        //         k++;
        //     }
        // }

        // while(k!=n){
        //     nums[k]=0;
        //     k++;
        // }        //easieer approach O(n)TC and O(1)SC

        int i=0, n=nums.size();

        for(int j=0; j<n; j++){
            if(nums[j]!=0){
                if(j!=i){
                    swap(nums[i], nums[j]);
                }
                i++;
            }
        }
    }
};