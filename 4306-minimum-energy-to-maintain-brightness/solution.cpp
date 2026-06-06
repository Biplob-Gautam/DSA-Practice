class Solution {
public:
    long long minEnergy(int n, int brightness, vector<vector<int>>& intervals) {
        long long total = 0;

        long long count=totalInterval(intervals);
        long long min = minBulb(n,brightness);

        total = count*min;
        return total;
    }


private:
    long long totalInterval(vector<vector<int>>& intervals){

        if(intervals.empty()) return 0;

        sort(intervals.begin(), intervals.end());

        long long count = 0;

        vector<int> current = intervals[0];

        for(int i=1; i<intervals.size(); i++){
            if(intervals[i][0] <= current[1]){
                current[1] = max(current[1], intervals[i][1]);
            }

            else{
                count+= 1LL * current[1] - current[0] +1;
                current = intervals[i];
            }
        }
        count += 1LL * current[1] - current[0] +1;
        return count;
        
    }

    long long minBulb(int n, int brightness){
        if(brightness>n) return -1;
        return (brightness+2)/3;
    }
};
