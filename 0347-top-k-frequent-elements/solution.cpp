class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        for(int i=0; i<nums.size(); i++){
            mpp[nums[i]]++;
        }

        vector<pair<int,int>> arr;
        for(auto& x : mpp){
            arr.push_back({x.first,x.second});
        }

        sort(arr.begin(), arr.end(), [](const pair<int,int>& a, const pair<int,int>& b) {
            return a.second > b.second;
        });   //this is having a pointer from begin to end compare 2 pair.second and send result in descending a<b for ascending


        vector<int> result;
        for(int i=0; i<k; i++){
            result.push_back(arr[i].first);
        }
        return result;
    }
};
