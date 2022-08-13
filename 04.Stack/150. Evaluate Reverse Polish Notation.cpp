/*
    Evaluate RPN, valid operators: +, -, *, /

    Stack, if num push, if operator apply to top 2 nums

    Time: O(n)
    Space: O(n)
*/

// Solution (NeetCode)
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        
        for (int i=0; i<tokens.size(); i++) {
            string token = tokens[i];
            // cout << token[0] << endl;
            if (token.size() > 1         //注意：是因有雙位數，或負數的存在
                || isdigit(token[0])) {  //注意：isdigit()是用於檢查輸入的字符是否為數字字符[0-9]
                stk.push(stoi(token));  //注意stoi()的使用
                continue;  //注意：這裡要用continue跳到下一個loop
            }
                           
            int num2 = stk.top();
            stk.pop();
            int num1 = stk.top();
            stk.pop();
                
            if (token=="+") {
                stk.push(num1 + num2);
            }
            else if (token=="-") {
                stk.push(num1 - num2);
            }
            else if (token=="*") {
                stk.push(num1 * num2);
            }
            else if (token=="/") {
                stk.push(num1 / num2);
            } 
        }
        return stk.top();
    }
};

