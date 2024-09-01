class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> s;
        string operators = "+-*/";
        for(int i = 0; i < tokens.size(); i++){
            s.push(tokens[i]);
            for(int j = 0; j < 4; j++){
                if(tokens[i][0] == operators[j]&&tokens[i].length()==1){
                    s.pop();
                    int num2 = stoi(s.top());
                    s.pop();
                    int num1 = stoi(s.top());
                    s.pop();
                    int num3;
                    if(operators[j]=='+'){
                        num3 = num1 + num2;
                    }else if(operators[j]=='-'){
                        num3 = num1 - num2;
                    }else if(operators[j]=='*'){
                        num3 = num1 * num2;
                    }else if(operators[j]=='/'){
                        num3 = num1 / num2;
                    }
                    s.push(to_string(num3));
                    break;
                }
            }
        }
        return stoi(s.top());
    }
};