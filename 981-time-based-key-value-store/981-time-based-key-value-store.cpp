class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>>tmp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        tmp[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        vector<pair<int,string>>&t=tmp[key];
        int l=0,r=t.size()-1;
        string ans="";
        while(l<=r){
            int m=(l+r)/2;
            if(t[m].first<=timestamp){
                ans=t[m].second;
                l=m+1;
            }
            else
                r=m-1;
        }
        return ans;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */