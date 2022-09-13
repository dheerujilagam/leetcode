class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if(n==0)
            return tasks.size();
        else{
            map<char,int>mp;
            int c=0;
            for(auto i:tasks){
                mp[i]++;
                if(c<mp[i])
                    c=mp[i];
            }
            int ct=0;
            for(auto it:mp){
                if(it.second==c)
                    ct++;
            }
            if(c+ct-1+((c-1)*n)<tasks.size())
                return (c+ct-1+((c-1)*n))+tasks.size()-(c+ct-1+((c-1)*n));
            else
                return c+ct-1+((c-1)*n);
        }
    }
};