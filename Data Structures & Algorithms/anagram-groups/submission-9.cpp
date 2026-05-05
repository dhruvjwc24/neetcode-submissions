class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> kv;

        for (const string& str : strs) {
            string key = str; sort(key.begin(), key.end());
            kv[key].emplace_back(str);
        }

        vector<vector<string>> out;
        for (auto& p : kv) {
            out.push_back(p.second);
        }

        return out;
    }
};
