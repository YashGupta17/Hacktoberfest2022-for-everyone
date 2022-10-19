class Solution {
public:
    unordered_map<string,int> m;
    bool isScramble(string a, string b) {
        if(a.size()!=b.size()){
            return false;
        }if(a.size()==0 and b.size()==0){
            return true;
        }
        if(a.compare(b)==0){
            return true;
        }if(a.size()<=1){
            return false;
        }
        string key= a+" "+ b;
        if(m.find(key)!=m.end()){
            return m[key];
        }int n=a.length();
        bool flag=false;
        for(int i=1;i<n;i++){
            if((isScramble(a.substr(0,i),b.substr(n-i,i))==true&&
               isScramble(a.substr(i,n-i),b.substr(0,n-i))==true)
                                    ||
               (isScramble(a.substr(0,i),b.substr(0,i))==true&&
               isScramble(a.substr(i,n-i),b.substr(i,n-i))==true)){
                flag = true;break;
            }
        }
    return m[key]=flag;
    }
};
