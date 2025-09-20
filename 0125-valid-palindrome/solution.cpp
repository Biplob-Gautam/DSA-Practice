class Solution {
public:
    bool isPalindrome(string s) {
        string cleaned = cleanString(s);

        int i=0,j=cleaned.length()-1;
        while(i<j){
            if(cleaned[i]!=cleaned[j]) return false;
            i++;
            j--;
        }
        return true;
    }

private: 

    string cleanString(const string &s) {
    string result;
    for (char c : s) {
        if (isalnum(c)) {                   // keep only alphanumeric
            result.push_back(tolower(c));   // convert to lowercase
        }
    }
    return result;
}
};
