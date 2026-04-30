class Solution {
// public:
//     int trap(vector<int>& height) {
//     int n = height.size();
//     vector<int> leftMax(n), rightMax(n);

//     leftMax[0] = height[0];
//     for (int i = 1; i < n; i++)
//         leftMax[i] = max(leftMax[i-1], height[i]);

//     rightMax[n-1] = height[n-1];
//     for (int i = n-2; i >= 0; i--)
//         rightMax[i] = max(rightMax[i+1], height[i]);

//     int water = 0;

//     for (int i = 0; i < n; i++) {
//         water += min(leftMax[i], rightMax[i]) - height[i];
//     }

//     return water;
// }


public:
    int trap(vector<int> & height){
        int n = height.size();
        int lmax=0,rmax=0;
        int l=0, r=n-1;
        int water=0;

        while(r>l){

            if(height[l]<height[r]){
                if(lmax <= height[l]) lmax = height[l];
                else water += lmax - height[l];
                l++;
            }
            else{
                if(rmax <= height[r]) rmax = height[r];
                else water += rmax - height[r];
                r--;
            }

        }
        return water;        
    }
};

