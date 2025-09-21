class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0,r=0,maxLen=0;
        vector<int> hash(256,-1);
        while(r<s.length()){
            int len=0;
            if(hash[s[r]] != -1 && hash[s[r]]>=l){
                l=hash[s[r]]+1;
            }
            hash[s[r]]=r;
            len = r-l+1;
            maxLen=max(len,maxLen);
            r++;
        }
        return maxLen;
    }
};
