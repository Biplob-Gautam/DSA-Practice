class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n=asteroids.size() , maxEle;
        stack<int> st;
        for(int i=0 ; i<n; i++){
            bool destroyed = false;

            while(!st.empty() &&  asteroids[i]<0 && st.top()>=0){

                if(abs(asteroids[i]) > st.top()){
                    st.pop();
                    continue;
                }
                else if(abs(asteroids[i]) == st.top()){
                    st.pop();
                    destroyed = true;
                    break;
                }
                else if(abs(asteroids[i]) < st.top()){
                    destroyed = true;
                    break;
                }
            }

            if(!destroyed) st.push(asteroids[i]);
        }

        vector<int> res(st.size());
        for(int i =st.size()-1; i>=0 ; i--){
            res[i]=st.top();
            st.pop();
        }
        return res;
    }
};
