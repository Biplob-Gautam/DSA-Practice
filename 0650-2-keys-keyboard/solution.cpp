class Solution {
public:
    int minSteps(int n) {
        int count=0,d=2;
        while(d*d<=n){
            while(n%d==0){
                n/=d;
                count+=d;
            }
            d++;
        }
        if(n>1) count+=n;
        return count;
    }
};
