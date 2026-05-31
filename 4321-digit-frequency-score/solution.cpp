class Solution {
public:
    int digitFrequencyScore(int n) {
        long long count=0;
        while(n){
            int temp = n%10;
            count+=temp;
            n=n/10;
        }
        return int(count);
    }
};
