/*
    Given n pairs of parentheses, generate all combos of well-formed parentheses
    Ex. n = 3 -> ["((()))","(()())","(())()","()(())","()()()"], n = 1 -> ["()"]

    Backtracking, keep valid, favor trying opens, then try closes if still valid

    Time: O(2^n)
    Space: O(n)
*/

// Solution1 (NeetCode)
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        generate(n, 0, 0, "", result);
        return result;
    }
private:
    void generate(int n, int open, int close, string str, vector<string>& result) {
        if (open == n && close == n) {
            result.push_back(str);
            return;
        }
        if (open < n) {
            generate(n, open + 1, close, str + '(', result);
        }
        if (open > close) {
            generate(n, open, close + 1, str + ')', result);
        }
    }
};


// Solution2 (My implementation) 只差在result宣告的位置
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        
        backtrack(n, 0, 0, "");
        return res;
        
    }
private:
    vector<string> res;
    void backtrack(int n, int openN, int closeN, string str) {
        if (openN==n && closeN==n) {
            res.push_back(str);
            return;
        }
        
        if (openN < n) {
            // str += "(";  //先加是不對的。
            // backtrack(n, openN+1, closeN, str);
            backtrack(n, openN+1, closeN, str+"(");
        }
        
        if (closeN < openN) {
            // str += ")";
            // backtrack(n, openN, closeN+1, str);
            backtrack(n, openN, closeN+1, str+")");
        }
        
        return;
    }
};