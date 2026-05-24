// class Solution {
// public:
//     vector<int> limitOccurrences(vector<int>& nums, int k) {
//         vector<int> ans;
//         unordered_map<int,int> mp;
//         int n=nums.size();

//         for(int x: nums){
//             mp[x]++;
//         }

//         for(int i=0; i<n; i++){
//             if(mp[nums[i]]==0) continue;
//             if(mp[nums[i]]>=k){
//                 int m=k;
//                 while(m){
//                     ans.push_back(nums[i]);
//                     m--;
//                 }
//                 mp[nums[i]]=0;
//             }
//             if(mp[nums[i]]<k){
//                 int m=mp[nums[i]];
//                 while(m){
//                     ans.push_back(nums[i]);
//                     m--;
//                 }
//                 mp[nums[i]]=0;
//             }
//         }
//         return ans;
//     }
// };


class Solution{
public:
    vector<int> limitOccurrences(vector<int>& nums, int k){
        vector<int> ans;
        int count=0;

        for(int i=0; i<nums.size(); i++){
            if(i==0 || nums[i]!=nums[i-1])count=1;
            else count++;

            if(count<=k)ans.push_back(nums[i]);
        }
        return ans;
    }
    
};
