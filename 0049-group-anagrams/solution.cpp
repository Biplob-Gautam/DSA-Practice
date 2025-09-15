class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mpp;

        for(int i=0; i<strs.size(); i++){
            string s = strs[i];
            sort(strs[i].begin(), strs[i].end());
            mpp[strs[i]].push_back(s);
        }
        vector<vector<string>> ans;
        for(auto x: mpp){
            ans.push_back(x.second);
        }

        return ans;
    }
};
