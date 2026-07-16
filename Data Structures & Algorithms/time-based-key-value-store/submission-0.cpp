class TimeMap {
    unordered_map<string, map<int,string>>mp;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        auto pt = mp[key].upper_bound(timestamp);
        if(pt == mp[key].begin())return "";
        pt--;
        return pt->second;
    }
};
