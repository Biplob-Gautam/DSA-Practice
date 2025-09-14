class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        unordered_map<int,int> Hmpp;
        for(char c:s) Hmpp[c]++;
        for(char c:t) Hmpp[c]--;

        for(auto i:Hmpp){
            if(i.second!=0) return false;
        }
        return true;
    }
};
