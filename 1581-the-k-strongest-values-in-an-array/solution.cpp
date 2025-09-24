class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        int m = (arr.size()-1)/2;
        vector<int> res;
        int i=0,j=arr.size()-1;
        while(k--){         //maine kiya tha i<=j
            if(abs(arr[i]-arr[m])>abs(arr[j]-arr[m])){
                res.push_back(arr[i]);
                i++;
            }
            else if(abs(arr[i]-arr[m])==abs(arr[j]-arr[m]) && arr[i]>arr[j]){
                res.push_back(arr[i]);
                i++;
            }
            else{
                res.push_back(arr[j]);
                j--;
            }            
//if you dont use this line then you need to make a new vector to store 
        }                   //and that degrades th SC k-- helps a lot
        // vector<int> ans(res.begin(), res.begin() + k);
        return res;   
    }
};
