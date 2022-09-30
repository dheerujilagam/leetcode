class Solution {
public:
    int search(vector<int>& nums, int target) {
        vector<pair<int,int>>mp;
        for(int i=0;i<nums.size();i++)
            mp.push_back({nums[i],i});
        sort(mp.begin(),mp.end());
        int i=0,j=nums.size()-1,mid;
        while(i<=j){
            mid=(i+j)/2;
            if(mp[mid].first==target)
                return mp[mid].second;
            else if( mp[mid].first<target)
                i=mid+1;
            else 
                j=mid-1;
        }
        return -1;
    }
};