class Solution {
public:
    string pushDominoes(string d) {
        int n=d.size();
        int l[n],r[n];
        int ind=-1;
        for(int i=n-1;i>=0;i--){
            if(d[i]=='L')
                ind=i;
            if(d[i]=='R')
                ind=-1;
            l[i]=ind;
        }
        ind=-1;
        for(int i=0;i<n;i++){
            if(d[i]=='L')
                ind=-1;
            if(d[i]=='R')
                ind=i;
            r[i]=ind;
        }
        string s="";
        for(int i=0;i<n;i++){
            if(l[i]==-1 and r[i]==-1)
                s+='.';
            else if(l[i]==-1 and r[i]!=-1)
                s+='R';
            else if(l[i]!=-1 and r[i]==-1)
                s+='L';
            else{
                if(abs(i-l[i])==abs(i-r[i]))
                    s+='.';
                else if(abs(i-l[i])<abs(i-r[i]))
                    s+='L';
                else
                    s+='R';
            }
        }
        return s;
    }
};