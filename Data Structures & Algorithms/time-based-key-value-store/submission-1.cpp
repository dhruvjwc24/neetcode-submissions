class TimeMap {
public:
    unordered_map<string, vector<pair<string, int>>> pam;

    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        pam[key].emplace_back(value, timestamp);
    }
    
    string get(string key, int timestamp) {
        auto it = pam.find(key);
        if (it == pam.end()) return "";

        vector<pair<string, int>>& vals = it->second;

        int lower = 0; int upper = vals.size() - 1;
        string ret;

        while (lower <= upper) {
            int mid = lower + (upper - lower) / 2;

            if (vals[mid].second > timestamp) {
                upper = mid - 1;
            } else if (vals[mid].second < timestamp) { // need to search right of val
                ret = vals[mid].first;
                lower = mid + 1;
            } else { // great! we found it, return the string
                return vals[mid].first; 
            }
        }

        return ret;
    }
};
