#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>ordered_set;
class Solution {
public:
    vector<int> countSmaller(vector<int>& arr) {
        int n=arr.size();
        ordered_set p;
	    vector<int>ans(n);
	    for(int i=n-1;i>=0;i--){
	        p.insert(arr[i]);
	        int val = p.order_of_key(arr[i]);
	        ans[i]=val;
	    }
	    return ans;
    }
};