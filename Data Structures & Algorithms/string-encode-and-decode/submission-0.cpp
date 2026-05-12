class Solution {
public:

    string encode(vector<string>& strs) {
        string encoding = "";
        for (auto& str : strs) {
            encoding += to_string(str.size()) + "#" + str;
        }

        return encoding;
    }

    vector<string> decode(string s) {
        int i = 0;
        vector<string> decoding;
        while (i < s.size()) {
            int j = i;
            while(s[j] != '#') ++j;
            int len = stoi(s.substr(i, j-i));
            i = ++j;
            decoding.emplace_back(s.substr(i, len));
            i+=len;
        }

        return decoding;
    }
};
