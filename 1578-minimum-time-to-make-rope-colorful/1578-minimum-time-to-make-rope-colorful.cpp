class Solution {
public:
    int minCost(string c, vector<int>& nt) {
        int i=0,j=1,sum=0;
        vector<vector<int>>v;
        while(i<c.size()){
            if(c[i]==c[j])
                j++;
            else{
                if((j-i)!=1){
                    vector<int>t;
                    for(int k=i;k<j;k++)
                        t.push_back(nt[k]);
                    sort(t.begin(),t.end());
                    v.push_back(t);
                }
                i=j;
                j++;
            }
        }
        for(auto i:v){
            for(int j=0;j<i.size()-1;j++)
                sum+=i[j];
        }
        return sum;
    }
};