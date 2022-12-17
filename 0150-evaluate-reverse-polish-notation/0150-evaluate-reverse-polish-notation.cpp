class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        // Lets call the stack as vals since we store values in it.
        stack<long> vals;

        for(int i=0;i<tokens.size();i++)
        {
            // if token[i] is an operator perform the following:
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")
            {
                // Pop last two elements in the stack
                long b = vals.top();
                vals.pop();
                long a = vals.top();
                vals.pop();
                // Perform operation based on the operator and push it to the stack
                if(tokens[i] == "+") vals.push(a+b);
                else if(tokens[i] == "-") vals.push(a-b);
                else if(tokens[i] == "*") vals.push(a*b);
                else vals.push(a/b);
            }
            // If its not an operator then it is an value, so push it to the stack
            else
                vals.push(stoi(tokens[i]));
        }

        // Return the last element left in the stack, i.e the top.
        return vals.top();
    }
};