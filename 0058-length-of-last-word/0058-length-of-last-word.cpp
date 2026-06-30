class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.size()-1;
        int cnt = 0;
        while(i>=0){
            if(s[i]!=' '){
                cnt++;
            }else if(cnt>0){
                break;
            }
            i--;
        }
        return cnt;
    }
};