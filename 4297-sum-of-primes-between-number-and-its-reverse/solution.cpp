class Solution {
public:
    int sumOfPrimesInRange(int n) {
        int original = n;
        int revN;

        while(n != 0){
            int digit = n%10;

            if(revN > INT_MAX/10 || revN < INT_MIN/10) return 0;
            
            revN = revN * 10 + digit;
            n /= 10;
        }

        int start = min(original, revN);
        int end = max(original, revN);

        int sum=0;

        for(int i = start; i<=end; i++){
            if(isPrime(i)) sum+=i;
        }

        return sum;
    }

private:
    bool isPrime(int n){
        if(n <=1) return false;

        for(int i=2; i*i<=n; i++){
            if(n%i == 0)return false;
        }

        return true;
    }
};
