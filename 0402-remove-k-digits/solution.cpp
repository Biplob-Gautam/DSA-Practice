class Solution {
public:
    string removeKdigits(string num, int k) {
        int n=num.length();
        
        stack<char> st;

        //you can do nums[i]-'0' < st.top() - '0' but ASCII values are such that there is no need for that and direct strinf substraction gives same result. this just converts them to int before substracting.

        for(int i=0; i<n; i++){
            while(k && !st.empty() && num[i]<st.top()){
                st.pop();
                k--;
            }
            st.push(num[i]);
        } 
        while(k){
            st.pop();
            k--;
        }

        if(st.empty())return "0";

        string res="";
        while(!st.empty()){
            // res = res+st.top();
            res.push_back(st.top());
            st.pop();
        }

        while(res.size() != 0 && res.back()=='0'){
            res.pop_back();
        }
        reverse(res.begin(), res.end());

        if(res.empty())return "0";
        return res;

        //return ans.empty() ? "0" : res;
    }
};
