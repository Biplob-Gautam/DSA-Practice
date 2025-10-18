class Solution {
public:
    bool isValid(string s) {
        //prev state
        stack<int> st;
        // if(s.size()==0 || s.size()==1)return false;

        for(int i=0; i<s.size(); i++){
            if(s[i]=='(' || s[i]=='[' || s[i]=='{') st.push(s[i]);

            else{
                if(st.size()==0)return false;

                char ch=st.top();
                st.pop();

                if(s[i]==')'&&ch=='(' || s[i]==']'&&ch=='[' || s[i]=='}'&&ch=='{')continue;
                else return false;
            }
        }
        return st.empty();
    }
};
