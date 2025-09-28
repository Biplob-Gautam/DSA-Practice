class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l=0,r=0;
        int maxLen=0;
        int fruitToErase;
        unordered_map<int,int> hash;

        while(r<fruits.size()){
            hash[fruits[r]] = r;

            if(hash.size()>2){
                int minIndex=INT_MAX;
                for(auto &x : hash){
                    if(x.second < minIndex){
                        minIndex = x.second;
                        fruitToErase=x.first;
                    }
                }    
                hash.erase(fruitToErase);
                l=minIndex+1;
            }
            maxLen=max(maxLen,r-l+1);
            r++;
        }
        return maxLen;
    }
};

