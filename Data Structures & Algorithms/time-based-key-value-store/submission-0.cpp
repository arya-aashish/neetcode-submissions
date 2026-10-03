class TimeMap {
private:
    unordered_map <string, vector<pair<int, string>>> mp;
public:
    TimeMap() {
            
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        int low= 0;
        int high= mp[key].size()-1;

        while (low<=high){
            if (mp.find(key)== mp.end())
                return "";
            int mid = low+(high-low)/2;
            
            if (mp[key][mid].first== timestamp)
                return mp[key][mid].second;
            else if (mp[key][mid].first>timestamp)
                high= mid-1;
            else 
                low= mid+1;
        }
        if (high>=0)
            return mp[key][high].second;
        return "";
    }
};
