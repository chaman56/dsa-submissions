class TimeMap {
    unordered_map<string, pair<vector<int>, vector<string>>>mp;
public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        mp[key].first.push_back(timestamp);
        mp[key].second.push_back(value);
    }
    
    string get(string key, int timestamp) {
        auto ub = upper_bound(mp[key].first.begin(), mp[key].first.end(), timestamp);
        if(ub == mp[key].first.begin())return "";
        ub--;
        return mp[key].second[distance(mp[key].first.begin(), ub)];
    }
};