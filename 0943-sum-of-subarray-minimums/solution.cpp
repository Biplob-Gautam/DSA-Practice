class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        long long sum=0,mod=1e9+7;
        int n=arr.size();

        int nsi[n], psi[n];
        stack<int> st;

        for(int i=n-1; i>=0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            if(st.empty()) nsi[i]=n;
            else nsi[i] = st.top();
            st.push(i);
        }

        while(!st.empty()) st.pop();

        for(int i=0; i<n; i++){
            while(!st.empty() && arr[st.top()]> arr[i]) st.pop();
            if(st.empty()) psi[i]=-1;
            else psi[i] = st.top();
            st.push(i);
        }

        for(int i=0 ; i<n ; i++){
            long long nextIndex = nsi[i]-i;
            long long prevIndex = i-psi[i];
            long long subarray = nextIndex * prevIndex;
            long long contri = (subarray*arr[i]) % mod;

            sum = (sum + contri)%mod;
        }
        return (int)sum;
    }
};
