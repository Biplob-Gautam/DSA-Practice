class Solution {
public:
    bool consecutiveSetBits(int n) {
        // int count=0; 

        // while (n>0){
        //     if((n&3) == 3)count++;
        //     n>>=1;
        // }

        // return count==1;



        int pairs = n & (n>>1);

        return __builtin_popcount(pairs) == 1;
    }
};
