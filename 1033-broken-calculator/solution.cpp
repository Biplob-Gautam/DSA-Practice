class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int count=0;
        while(startValue<target){
            if(target%2==0){
                target/=2;
                count++;
            }
            else if(target%2==1){
                target++;
                count++;
            }
        }
        return count+(startValue-target); //if target become -ve then only addition can do no. od addition = 
                                        //startValue-target
    }
};
