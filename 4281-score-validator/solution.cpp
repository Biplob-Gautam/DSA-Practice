class Solution {
public:
    vector<int> scoreValidator(vector<string>& events) {
        int score=0,counter=0;
        int n =events.size();
        
        for(int i=0; i<n && counter<10; i++){
            if(events[i] == "W") counter++;
            else if(events[i] == "WD" || events[i] == "NB") score++;
            else{
                score = score + stoi(events[i]);
            }
        }

        vector<int> res;
        res.push_back(score);
        res.push_back(counter);
        return res;
    }
};
