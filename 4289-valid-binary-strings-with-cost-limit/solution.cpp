class Solution {
public:
    vector<string> ans;
    vector<string> generateValidStrings(int n, int k) {
        string s ="";
        solve(0,n,k,0,s);
        return ans;
    }

private:
    void solve(int idx, int n, int k, int cost, string &s){
        if(cost>k)return;
        if(idx == n){
            ans.push_back(s);
            return;
        }

        s.push_back('0');
        solve(idx+1,n,k,cost,s);
        s.pop_back();

        if(idx==0 || s[idx-1]=='0'){
            s.push_back('1');
            solve(idx+1,n,k,cost+idx, s);
            s.pop_back();
        }
    }
};
