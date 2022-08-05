class Solution {
public:
    int search(vector<int>& vec, int target) {
        int l=0,r=vec.size()-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(vec[mid]==target)
                return mid;
            else if(vec[mid]>target)
                r=mid-1;
            else
                l=mid+1;
        }
        return -1;
    }
};