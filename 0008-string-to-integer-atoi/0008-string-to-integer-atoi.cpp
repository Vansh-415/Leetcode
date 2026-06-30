class Solution {
public:
    int myAtoi(string s) {
        int sign = 1;
        int result = 0;
        int i = 0;
        int n  = s.size();

        while(i < n && s[i]==' '){
             i++;
        }

        if(i==n) return 0;

        if(s[i]=='-'){
            sign = -1;
            i++;
        }else if(s[i]=='+'){
            sign = 1;
            i++;
        }

        while(i < n && s[i]>='0' && s[i]<='9'){
            int digit = s[i] - '0';
            if(result > INT_MAX/10 || (result==INT_MAX/10 && digit > 7)){
                if(sign == 1){
                    return INT_MAX;
                }else{
                    return INT_MIN;
                }
            }
            result = (result * 10) + digit;
            i++;
        }
            
        
        return result*sign;
    }
};