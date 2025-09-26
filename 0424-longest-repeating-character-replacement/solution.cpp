class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0, r = 0;  
        int maxCount = 0;    // count of the dominant character in the current window
        int maxLen = 0;
        vector<int> freq(26, 0);

        while (r < s.length()) {
            freq[s[r] - 'A']++;
            maxCount = max(maxCount, freq[s[r] - 'A']);
            while ((r - l + 1) - maxCount > k) {
                freq[s[l] - 'A']--;
                l++;
            }
            maxLen = max(maxLen, r - l + 1);
            r++;
        }
        return maxLen;
    }
};

