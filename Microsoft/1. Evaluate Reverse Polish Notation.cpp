class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        //evaluate polish notation

        long long ans;
        
        stack<long long> stk;
        int n = tokens.size();
        for(int i = 0; i < n; i++) {
            string token = tokens[i];
            if(token != "+" && token != "-" && token != "/" && token != "*") {
                //if it is a number then push in stack
                stk.push(stoi(token));
            } else {
                //whenever we encounter a symbol 
                //take 2 numbers from top , perform the operation and push back in stack
                long long a  = stk.top();
                stk.pop();
                long long b = stk.top();
                stk.pop();
                long long cal = 0;
                if(token == "+") {
                    cal = a + b;
                    stk.push(cal);

                } else if (token == "-") {
                    cal = b - a;
                    stk.push(cal);
                }else if(token == "/") {
                    cal = b / a;
                    stk.push(cal);
                } else {
                    cal = a * b;
                    stk.push(cal);
                }
            }
        }
        //ans lies on the top of the stack
        ans = stk.top();
        return ans;
    }
};
