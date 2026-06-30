class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        sort(strs.begin(),strs.end());
        string first = strs[0];
        string last = strs[strs.size()-1];
        string ans = "";
        int mini = min(first.size(),last.size());
        int cnt = 0;
        for(int i = 0 ; i < mini ; i ++){
            if(first[i]!=last[i]) break;

            ans+=first[i];
        } 
        return ans;
    }
};