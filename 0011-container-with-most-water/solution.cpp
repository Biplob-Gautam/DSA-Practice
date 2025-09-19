class Solution {
public:
    int maxArea(vector<int>& height) {
        // int n=height.size(),maxArea=0;
        // for(int i=0; i<n; i++){
        //     for(int j=i+1; j<n; j++){
        //         int area=(j-i)*min(height[i],height[j]);
        //         maxArea=max(maxArea,area);
        //     }
        // }
        // return maxArea;

        //good brute force - beginner approach but TLE so optimize it

        int i=0,j=height.size()-1,water=0;
        while(i<j){
            water = max(water, (j-i)*min(height[i],height[j]));

            if(height[i]<height[j]) i++;
            else j--;
        }
        return water;
    }
};
