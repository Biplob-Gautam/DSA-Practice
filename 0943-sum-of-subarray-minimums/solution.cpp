class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int mod=1e9+7;
        int n = arr.size();
        long long nextIndex,prevIndex, noOfSubarray, contri;
        long long sum =0;
        vector<int> nseArr(n),psoeeArr(n);

        nseArr = nse(arr);
        psoeeArr = psoee(arr);

        for(int i=0; i<n; i++){
            nextIndex = nseArr[i] - i;
            prevIndex = i - psoeeArr[i];
            noOfSubarray = nextIndex * prevIndex;
            contri = (noOfSubarray * arr[i] * 1LL) % mod;
            sum = (sum+contri) % mod;
        }

        return (int)sum;
    }

private:
    vector<int> nse( vector<int> &num){
        stack<int> st;
        int n = num.size();
        vector<int> nse(n);

        for(int i=n-1; i>=0; i--){
            while(!st.empty() && num[i]<=num[st.top()]) st.pop();

            if(st.empty()) nse[i] = n;
            else nse[i] = st.top();

            st.push(i);
        }
        return nse;
    }

    vector<int> psoee( vector<int> &num){
        stack<int> st;
        int n = num.size();
        vector<int> psoee(n);

        for(int i=0; i<n; i++){
            while(!st.empty() && num[i]<num[st.top()]) st.pop();

            if(st.empty()) psoee[i] = -1;
            else psoee[i] = st.top();

            st.push(i);
        }
        return psoee;
    }
};
