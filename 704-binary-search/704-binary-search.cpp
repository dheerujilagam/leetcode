class Solution {
public:
    int search(vector<int>& vec, int target) {
        vector<int>::iterator it;
        it = find (vec.begin(), vec.end(), target);
        if (it != vec.end()){
            return it-vec.begin();
        }
        else
            return -1;
    }
};