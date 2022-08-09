class Solution {
public:
    vector<int> findAnagrams(string txt, string pat) {
        if(txt.size() < pat.size())return {};
	    int N = txt.size();
	    int k = pat.size();
	    vector<int> res;
	    vector<int> txtM(26,0);
	    vector<int> patM(26,0);
	    int j = 0;
	    for(int i = 0; i < k; i++){
	        txtM[txt[i]-'a']++;
	        patM[pat[i]-'a']++;
	    }
	    if(txtM == patM)res.push_back(0);
	    for(int i = k; i < N; i++){
	        txtM[txt[j]-'a']--;
	        txtM[txt[i]-'a']++;
            j++;
	        if(txtM == patM)res.push_back(j);
	    }
	    return res;
	
    }
};