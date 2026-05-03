class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()) return false;

        string dablu = s+s;

        return dablu.find(goal) != string::npos;
    }
};
