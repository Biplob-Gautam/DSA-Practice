class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        if(matrix.empty()) return 0;

        int m=matrix[0].size();

        vector<int> height(m,0);
        
        int maxArea=0;

        for(int row=0; row<n; row++){
            for(int col=0; col<m; col++){
                if(matrix[row][col] == '1')height[col]++;
                else height[col] = 0;
            }
            int area = largestRectangleArea(height);

            maxArea = max(area, maxArea);
        }
        return maxArea;
    }


private:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> nse(n,n), pse(n,-1);
        stack<int> st;

        for(int i=n-1; i>=0; i--){
            while(!st.empty() && heights[st.top()]>=heights[i])st.pop();

            if(!st.empty())nse[i]=st.top();

            st.push(i);
        }

        while(!st.empty())st.pop();

        for(int i=0; i<n; i++){
            while(!st.empty() && heights[st.top()]>=heights[i])st.pop();

            if(!st.empty())pse[i]=st.top();

            st.push(i);
        } 

        int Maxarea=0;
        for(int i=0; i<n; i++){
            int width = nse[i] - pse[i] - 1;
            int area = width * heights[i];
            Maxarea = max(Maxarea, area);
        }

        return Maxarea;
    }
};
