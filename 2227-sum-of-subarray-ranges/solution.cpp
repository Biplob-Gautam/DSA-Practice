class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long minSum = sumSubarrayMins(nums);
        long long maxSum = sumSubarrayMaxs(nums);
        long long range = maxSum - minSum;
        return range;
    }

private:
    long long sumSubarrayMins(vector<int>& arr) {
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
        for(int i=0; i<n; i++){
            int nextIndex = nsi[i] - i;
            int prevIndex = i - psi[i];
            long long numSubarray = 1LL * nextIndex * prevIndex;
            long long contri = (numSubarray * arr[i]);
            sum = (sum + contri);
        }

        return sum;
    }

    long long sumSubarrayMaxs(vector<int>& arr) {
        int n = arr.size();

        vector<int> nsi(n), psi(n);
        stack<int> st;

        for(int i=n-1; i>=0; i--){
            while(!st.empty() && arr[st.top()]<=arr[i])st.pop();
            if(st.empty())nsi[i]=n;
            else nsi[i]=st.top();
            st.push(i);
        }
        while(!st.empty())st.pop();
        for(int i=0; i<n; i++){
            while(!st.empty() && arr[st.top()]<arr[i])st.pop();
            if(st.empty())psi[i]=-1;
            else psi[i]=st.top();
            st.push(i);
        }

        long long sum=0;
        for(int i=0; i<n; i++){
            int nextIndex = nsi[i] - i;
            int prevIndex = i - psi[i];
            long long numSubarray = 1LL * nextIndex * prevIndex;
            long long contri = (numSubarray * arr[i]);
            sum = (sum + contri);
        }

        return sum;
    }
};
