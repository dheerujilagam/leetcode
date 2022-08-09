class Solution {
public:
    int change(int n){
        stack<int>s;
        while(n){
            s.push(n%10);
            n/=10;
        }
        int val=0;
        while(!s.empty()){
            if(s.top()!=9){
                val=(val*10)+9;
                s.pop();
                break;
            }
            else{
                val=(val*10)+s.top();
                s.pop();
            }
        }
        while(!s.empty()){
            val=(val*10)+s.top();
            s.pop();
        }
        return val;
    }
    int maximum69Number (int num) {
        return change(num);
    }
};