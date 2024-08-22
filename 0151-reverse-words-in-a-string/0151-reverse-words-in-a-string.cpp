class Solution {
public:
    string reverseWords(string s) {
        string sub = "";
        vector<string> v;
        for(int i = 0; i < s.length(); i++){
            if(s[i]==' ' && sub!=""){
                v.push_back(sub);
                sub = "";
            }else if(s[i]!=' '){
                sub+=s[i];
            }
        }
        if(sub!=""){
            v.push_back(sub);
            sub = "";
        }
        s = v[v.size()-1];
        for(int i = v.size()-2; i > -1; i--){
            cout << v[i] << endl;
            s+=" ";
            s+=v[i];
        }
        return s;
    }
};