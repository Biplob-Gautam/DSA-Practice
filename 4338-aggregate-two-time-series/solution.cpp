class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1,
                                            vector<vector<int>>& series2) {

        auto ferilonsar = make_pair(series1, series2);

        vector<vector<int>> ans;

        int n = series1.size();
        int m = series2.size();

        int i = 0, j = 0;

        while (i < n || j < m) {
            int t;
            
            if (j == m || (i < n && series1[i][0] < series2[j][0])) t = series1[i][0];
            else if (i == n || series2[j][0] < series1[i][0]) t = series2[j][0];
            else t = series1[i][0];

            int val1 = 0;
            int val2 = 0;

            if (i < n) val1 = series1[i][1];
            if (j < m) val2 = series2[j][1];

            ans.push_back({t, val1 + val2});

            if (i < n && series1[i][0] == t) i++;
            if (j < m && series2[j][0] == t) j++;
        }
        return ans;
    }
};
