class Solution {
public:
    int sumOfGoodIntegers(int n, int k) {
        int sum=0;

        for(int x=n-k; x<=n+k; x++){
            if(x>=0 && (n & x) == 0)sum+=x;
        }
        return sum;
    }
};
