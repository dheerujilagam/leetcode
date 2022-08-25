class Solution {
public:
    int minSwaps(string s) {
        int c=0,k=0;
        for(auto ch:s)
        {
            if(ch=='[')
                c++;
            else
                c--;
            if(c<0){
                k+=1;
                c=0;
            }

        } 
        return (k+1)/2;
        
    }
};