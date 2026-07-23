class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();

        vector<int> nsi(n), psi(n);
        stack<int> st;

        for(int i=n-1; i>=0; i--){
            while(!st.empty() && arr[st.top()]>=arr[i])st.pop();
            if(st.empty())nsi[i]=n;
            else nsi[i]=st.top();
            st.push(i);
        }
        while(!st.empty())st.pop();
        for(int i=0; i<n; i++){
            while(!st.empty() && arr[st.top()]>arr[i])st.pop();
            if(st.empty())psi[i]=-1;
            else psi[i]=st.top();
            st.push(i);
        }

        long long sum=0;
        long long mod = 1e9+7;
        for(int i=0; i<n; i++){
            int nextIndex = nsi[i] - i;
            int prevIndex = i - psi[i];
            long long numSubarray = 1LL * (nextIndex * prevIndex);
            long long contri = (numSubarray * arr[i]) % mod;
            sum = (sum + contri)%mod;
        }

        return (int)sum;
    }
};
