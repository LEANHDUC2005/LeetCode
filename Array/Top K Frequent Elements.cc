class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        for(int &i : nums){
            hash[i]++;
        }
        vector<pair<int,int>> v;
        for(auto &i : hash){
            v.push_back({i.first, i.second});
        }
        sort(v.begin(), v.end(), [](auto &a, auto &b){
            return b.second < a.second;
        });

        vector<int> returnArr(k);
        for(int i=0; i < k; i++){
            returnArr[i] = v[i].first;
        }
        return returnArr;
    }
};
