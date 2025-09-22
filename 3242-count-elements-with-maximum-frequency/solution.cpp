class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> hash;
        for(int i=0;i<nums.size();i++){
            hash[nums[i]]++;
        }
        int maxFreq=0;
        for(auto &[num,freq] : hash){
            maxFreq = max(maxFreq,freq);
        }
        int total=0;
        for(auto &[num,freq] : hash){
            if(freq == maxFreq) total +=freq;
        }
        return total;
    }
};
