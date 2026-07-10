class TimeMap {
public:
    unordered_map<string, vector<pair<string, int>>> pam;

    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        pam[key].emplace_back(value, timestamp);
    }
    
    string get(string key, int timestamp) {
        vector<pair<string, int>>& vals = pam[key];
        int lower = 0; int upper = vals.size() - 1;
        string ret;

        while (lower <= upper) {
            int mid = lower + (upper - lower) / 2;

            if (vals[mid].second == timestamp) { // great! we found it, return the string
                return vals[mid].first; 
            } else if (vals[mid].second < timestamp) { // need to search right of val
                ret = vals[mid].first;
                lower = mid + 1;
            } else {
                upper = mid - 1;
            }
        }

        return ret;
    }
};
