class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int max_Wealth = 0;
        for (size_t i = 0; i < accounts.size(); i++) {
            int sum=0;
            for (size_t j = 0; j < accounts[i].size(); j++) {
                sum+=accounts[i][j];
                if(sum>max_Wealth) max_Wealth=sum;
            }
        }
        return max_Wealth;
    }
};
