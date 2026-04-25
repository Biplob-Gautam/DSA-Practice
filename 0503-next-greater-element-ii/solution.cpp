class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> nge(n,-1);

        for(int i=(2*n-1); i>=0; i--){
            while(!st.empty() && nums[st.top()]<=nums[i%n]) st.pop();

            if(i<n){
                if(st.empty()) nge[i]=-1;
                else nge[i]=nums[st.top()];
            }

            st.push(i%n);
        }
        return nge;
    }
};
