class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        string open = "([{";
        string close = ")]}";
        for(int i = 0; i < s.length(); i++){
            auto c = s[i];
            auto openFind = open.find(c);
            if(openFind!=string::npos){
                st.push(c);
                cout << c << endl;
            }else{
                if(st.empty()){
                    return false;
                }
                if(!((c==')'&&st.top()=='(')||(c==']'&&st.top()=='[')||(c=='}'&&st.top()=='{'))){
                    cout << c << endl;
                    return false;
                }
                st.pop();
            }
        }
        if(!st.empty()){
            return false;
        }
        return true;
    }
};