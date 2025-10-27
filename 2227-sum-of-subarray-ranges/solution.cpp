// class Solution {
// public:
//     long long subArrayRanges(vector<int>& nums) {
//         long long sum=0, res=0;
//         int n=nums.size();
//         for(int i=0; i<n; i++){
//             int minVal=nums[i], maxVal=nums[i];
//             for(int j=i; j<n; j++){
//                 minVal = min(minVal,nums[j]);
//                 maxVal = max(maxVal,nums[j]);
//                 res = maxVal-minVal;
//                 sum += res;
//             }
//         }
//         return sum;
//     }
// };

class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {

       long long max_sum = sumSubarrayMax(nums);
       long long min_sum = sumSubarrayMins(nums);

       long long sum = max_sum - min_sum;

       return sum;
    }

private:

    long long sumSubarrayMins(vector<int>& arr) {
        int n= arr.size();
        vector<int>nse(n,0);
        vector<int>pse(n,0);
         
         
        stack<int>st;

        for(int i=n-1; i>=0; i--){
          while(!st.empty() && arr[st.top()]>= arr[i])
               st.pop();
          
           if(st.empty())    
                nse[i]=n;
            else
                nse[i] = st.top();

            st.push(i);
           
        }

        while(!st.empty()){
            st.pop();
        }
    for(int i=0; i<n; i++){
          while(!st.empty() && arr[st.top()]> arr[i])
               st.pop();
          
           if(st.empty())    
                pse[i]=-1;
            else
                pse[i] = st.top();

            st.push(i);
           
        }
       long long left, right;
       long long total=0;

       for(int i=0; i<n; i++){
        left= i-pse[i];
        right = nse[i]-i;

        total= (total+ (left *right* 1ll * arr[i]));
       }
        return total;
    }

    long long sumSubarrayMax(vector<int>& arr) {
        int n= arr.size();
        vector<int>nge(n,0);
        vector<int>pge(n,0);
         
         
        stack<int>st;

        for(int i=n-1; i>=0; i--){
          while(!st.empty() && arr[st.top()] <= arr[i])
               st.pop();
          
           if(st.empty())    
                nge[i]=n;
            else
                nge[i] = st.top();

            st.push(i);
           
        }

        while(!st.empty()){
            st.pop();
        }
    for(int i=0; i<n; i++){
          while(!st.empty() && arr[st.top()] < arr[i])
               st.pop();
          
           if(st.empty())    
                pge[i]=-1;
            else
                pge[i] = st.top();

            st.push(i);
           
        }
       long long left, right;
       long long total=0;

       for(int i=0; i<n; i++){
        left= i-pge[i];
        right = nge[i]-i;

        total= (total+ (left *right* 1ll * arr[i]));
       }
        return total;
    }
    
};

/*
APPROACH EXPLANATION:

1. GOAL:
   For each subarray, range = (max - min).
   We want the sum of all such ranges for all subarrays.

2. OBSERVATION:
   Each element contributes as:
     → a maximum in some subarrays (+)
     → a minimum in some subarrays (−)

   So total = (sum of all max contributions) − (sum of all min contributions)

3. CONTRIBUTION COUNT:
   For element arr[i]:
     - When finding minimums:
         → PSE = Previous Smaller Element index
         → NSE = Next Smaller Element index
         → count of subarrays where arr[i] is minimum = (i - PSE[i]) * (NSE[i] - i)
     - When finding maximums:
         → PGE = Previous Greater Element index
         → NGE = Next Greater Element index
         → count of subarrays where arr[i] is maximum = (i - PGE[i]) * (NGE[i] - i)

4. COMPUTATION:
   sumSubarrayMax() → total contribution when each element acts as maximum
   sumSubarrayMins() → total contribution when each element acts as minimum
   Final Answer = max_sum − min_sum


*/
