class Solution {
public:
    int calculate(string s) {
        int n1 = 0, o1 = 1;
        vector<int> stk;
        
        for(int i=0; i<s.size(); i++){
            if(isdigit(s[i])){
                int num = s[i] - '0';
                while(i+1<s.size() && isdigit(s[i+1]))
                    num = num * 10 + (s[i++ +1] - '0');
                n1 = o1 == 1? n1+num: n1-num;
            }
            else if(s[i] == '('){
                stk.push_back(n1);
                stk.push_back(o1);
                n1 = 0, o1 = 1;
            }
            else if(s[i] == ')'){
                int num = n1;
                o1 = stk.back(); stk.pop_back();
                n1 = stk.back(); stk.pop_back();
                n1 = o1 == 1? n1+num: n1-num;
            }
            else if(s[i] == '+' || s[i] == '-'){
                o1 = s[i] == '+'? 1: -1;
            }
        }
        return n1;
    }
};
