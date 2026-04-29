class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int mod = 1e9+7;
        int n = arr.size();
        stack<int> st;
        vector<int> nsi(n,-1), psi(n,-1);

        for(int i =n-1; i>=0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();

            if(st.empty()) nsi[i]=n;
            else nsi[i]=st.top();
            st.push(i);
        }

        while(!st.empty()) st.pop();

        for(int i =0; i<n; i++){
            while(!st.empty() && arr[st.top()] > arr[i]) st.pop();

            if(st.empty()) psi[i]=-1;
            else psi[i]=st.top();
            st.push(i);
        }

        long long sum=0;
        for(int i=0; i<n; i++){
            int leftChoice = i - psi[i];
            int rightChoice = nsi[i] - i;
            int NoOfSubarrays = leftChoice * rightChoice;
            long long contri = NoOfSubarrays * (long long)arr[i];
            sum = (sum + contri) % mod; 
        }

        return (int)sum;
    }
};
