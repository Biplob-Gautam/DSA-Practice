class Solution {
public:
    bool isPalindrome(int x) {
        int y=0,val;
        val=x;
        if(x<0) return false;
        while(x!=0){
            int num = x%10;
            if(y > INT_MAX/10 || y< INT_MIN/10) return false;
            y=y*10+num;
            x = x/10;
        }
        if(y==val)return true;
        return false;
    }
};
