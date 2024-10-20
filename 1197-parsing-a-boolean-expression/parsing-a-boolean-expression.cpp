class Solution {
public:
    bool parseBoolExpr(string expression) {
        bool expr = false;
        stack<char> st, op;
        bool first = true;

        for (int i = 0; i < expression.size(); ++i) {
            if (expression[i] == '&' || expression[i] == '|' || expression[i] == '!') {
                op.push(expression[i]);
            }
            else if (expression[i] == ')') {
                vector<bool> operands;
                
                while (!st.empty() && st.top() != '(') {
                    char topVal = st.top();
                    st.pop();
                    if (topVal == 't' || topVal == 'f') {
                        operands.push_back(topVal == 't');
                    }
                }
                st.pop();
                
                char operation = op.top();
                op.pop();
                
                if (operation == '&') {
                    expr = true;
                    for (bool val : operands) {
                        expr &= val;
                    }
                }
                else if (operation == '|') {
                    expr = false;
                    for (bool val : operands) {
                        expr |= val;
                    }
                }
                else if (operation == '!') {
                    expr = !operands[0];
                }
                
                st.push(expr ? 't' : 'f');
            }
            else {
                st.push(expression[i]);
            }
        }

        return st.top() == 't';
    }
};
