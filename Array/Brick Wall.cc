class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int max_ans = 0;
        unordered_map<long long, int> verticalLine;
        vector<vector<long long>> prefix_wall;
        for(const auto &i : wall){
            prefix_wall.emplace_back(i.begin(), i.end());
        }
        for(int i=0; i < prefix_wall.size(); i++){
            for(int j=1; j < prefix_wall[i].size(); j++){
                prefix_wall[i][j] += prefix_wall[i][j - 1];
            }
        }

        for(int i=0; i < prefix_wall.size(); i++){
            for(int j=0; j < prefix_wall[i].size() - 1; j++){
                    verticalLine[prefix_wall[i][j]]++;
                    max_ans = max(verticalLine[prefix_wall[i][j]], max_ans);
            }
        }
        return wall.size() - max_ans;
    }
};
