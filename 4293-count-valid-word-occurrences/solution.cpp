class Solution {
public:
    vector<int> countWordOccurrences(vector<string>& chunks, vector<string>& queries) {
        string s = "";

        for(string str: chunks){
            s += str;
        }
        
        unordered_map<string,int> freq;
        string cur = "";
        int n = s.size();

        for(int i=0; i<n; i++){
            char ch=s[i];
            bool isLetter = (ch >= 'a' && ch <= 'z');
            bool validHyphen = false;

            if(ch == '-'){
                if(i>0 && i<n-1 && s[i-1]>='a' && s[i-1]<='z' && s[i+1]>='a' && s[i+1]<='z') validHyphen = true; 
            }

            if(isLetter || validHyphen) cur += ch;
            else{
                if(cur != ""){
                    freq[cur]++;
                    cur = "";
                }
            }
        }

        if(cur != "")freq[cur]++;
        
        vector<int> ans;
        for(string w: queries){
            ans.push_back(freq[w]);
        }
        
        return ans;
    }
};
