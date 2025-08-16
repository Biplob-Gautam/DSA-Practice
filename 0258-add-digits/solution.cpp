class Solution {
public:
    int sum(int n){
        int val=n,res=0;
        while(val!=0){
            res+=val%10;
            val=val/10;
        }
        return res;
    }
    int addDigits(int num) {
        int val=num;
        val=sum(val);
        while(val%10!=val){
           val=sum(val); 
        }
        return val;
    }
};
