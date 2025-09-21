class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l=0,r=1,maxProfit=0;
        while(r<prices.size()){
            int profit=0;
            if(prices[l]<prices[r]){
                profit=prices[r]-prices[l];
                maxProfit=max(maxProfit,profit);
                r++;
            }
            else{
                l=r;
                r++;
            }
        }
        return maxProfit;
    }
};
