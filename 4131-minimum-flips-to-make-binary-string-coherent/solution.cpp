class Solution {
public:
    int minFlips(string s) {
        int ones = 0, zeroes = 0;

        for(char c : s){
            if(c == '1') ones++;
            else zeroes++;
        }

        int ans = min(ones,zeroes);
        if(ones >= 1) ans = min(ans,ones-1);

        int n = s.size();

        if(n>=2){
            int middleOnes = 0;

            for(int i=1;i<n-1;i++){
                if(s[i] == '1')middleOnes++;
            }

            int cost = (s[0] == '0') + (s[n-1] == '0') + middleOnes;

            ans = min(ans,cost);
        }
        return ans;
    }
};
