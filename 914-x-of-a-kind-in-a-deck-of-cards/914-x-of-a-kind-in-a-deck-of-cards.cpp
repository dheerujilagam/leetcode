class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        //if(deck.size()==1) return false;
        unordered_map<int,int>mp;
        for(auto i:deck){
            mp[i]++;
        }
        int val=mp[deck[0]];
        for(auto it:mp)
            val=gcd(val,it.second);
        if(val<2) return false;
        for(auto it:mp){
            if(it.second%val!=0)
                return false;
        }
        return true;
    }
};