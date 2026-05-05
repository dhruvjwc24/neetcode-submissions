class Solution {
public:
    struct ArrayHash {
        size_t operator()(const array<int, 26>& a) const {
            size_t h = 0;
            for (int x : a) {
                h = h * 31 + hash<int>{}(x);
            }
            return h;
        }
    };

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<array<int, 26>, vector<string>, ArrayHash> kv;

        for (const string& str : strs) {
            array<int, 26> counts{};
            for (char ch : str) {
                ++counts[ch - 'a'];
            }

            kv[counts].emplace_back(str);
        }

        vector<vector<string>> out;
        for (auto& p : kv) {
            out.push_back(p.second);
        }

        return out;
    }
};
