class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n,0);

        int evenCount = 0;
        int oddCount = 0;
        
        for(int i=n-1; i>=0; i--){
            if(nums[i] % 2 == 0){
                res[i] = oddCount;
                evenCount++;
            }
            else{
                res[i] = evenCount;
                oddCount++;
            }
        }
        return res;
    }
};
