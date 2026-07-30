class Solution {
public:
    int minimumPushes(string word) {
        int cost=1;
        int len=word.length();
        int ans=0, remaining=0;

        while(len>0){
            int take = min(len, 8);
            ans += take * cost;
            len -= take;
            cost++;
        }

        return ans;
    }
};
