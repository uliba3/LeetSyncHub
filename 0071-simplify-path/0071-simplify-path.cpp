class Solution {
public:
    string simplifyPath(string path) {
        string word;
        stack<string> s;
        for(int i = 0; i < path.length(); i++){
            if(path[i]=='/'){
                if(word!=""){
                    if(word==".."){
                        if(!s.empty()){
                            s.pop();
                        }
                    }else if(word!="."){
                        s.push(word);
                    }
                    word="";
                }
                continue;
            }
            word+=path[i];
        }
        if(word!=""){
            if(word==".."){
                if(!s.empty()){
                    s.pop();
                }
            }else if(word!="."){
                    s.push(word);
            }
        }
        string out;
        if(s.empty()){
            return "/";
        }
        while(!s.empty()){
            out = "/" + s.top() + out;
            s.pop();
        }
        return out;
    }
};