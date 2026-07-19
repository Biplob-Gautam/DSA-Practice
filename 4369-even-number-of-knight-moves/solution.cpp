#include <bits/stdc++.h>
class Solution {
public:
    bool canReach(vector<int>& start, vector<int>& target) {
        int count=knightMoves(start, target);
        if(count%2==0)return true;
        return false;
        
    }

private:
    int knightMoves(vector<int> &start, vector<int> &target) {

    vector<pair<int,int>> moves = {
        {2,1}, {2,-1},
        {-2,1}, {-2,-1},
        {1,2}, {1,-2},
        {-1,2}, {-1,-2}
    };

        queue<pair<vector<int>, int>> q;
        vector<vector<bool>> visited(8, vector<bool>(8, false));

        q.push({start, 0});
        visited[start[0]][start[1]] = true;

        while (!q.empty()) {

            auto [curr, dist] = q.front();
            q.pop();

            if (curr == target)
                return dist;

            for (auto [dx, dy] : moves) {

                int nx = curr[0] + dx;
                int ny = curr[1] + dy;

                if (nx >= 0 && nx < 8 &&
                    ny >= 0 && ny < 8 &&
                    !visited[nx][ny]) {

                    visited[nx][ny] = true;
                    q.push({{nx, ny}, dist + 1});
                }
            }
        }

        return -1;
    }
};
