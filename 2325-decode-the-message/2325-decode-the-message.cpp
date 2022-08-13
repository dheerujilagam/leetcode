class Solution {
public:
    string decodeMessage(string key, string message) {
        unordered_map<char,char>decode;
        unordered_map<char,char>mp;
        int temp = 97;
        for(int i=0;i<key.size();i++){
            if(key[i]==' ') continue;
            if(!mp[key[i]]){
                mp[key[i]]++;
                decode[key[i]]=temp;
                temp++;
            }
        }
        string ans;
        for(int i=0;i<message.size();i++){
            if(message[i]==' ') ans.push_back(' ');
            else ans.push_back(decode[message[i]]);
        }
        return ans;
    }
};