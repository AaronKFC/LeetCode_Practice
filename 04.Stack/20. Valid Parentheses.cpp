/*
    Given s w/ '(, ), {, }, [, ]', determine if valid
    Ex. s = "()[]{}" -> true, s = "(]" -> false

    Stack of opens, check for matching closes & validity

    Time: O(n)
    Space: O(n)
*/

// Solution1 (NeetCode) faster
class Solution {
public:
    bool isValid(string s) {
        stack<char> open;
        
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
                if (open.empty()) {
                    return false;
                }
                if (s[i] == ')' && open.top() != '(') {
                    return false;
                }
                if (s[i] == '}' && open.top() != '{') {
                    return false;
                }
                if (s[i] == ']' && open.top() != '[') {
                    return false;
                }
                open.pop();
            } else {
                open.push(s[i]);
            }
        }
        
        if (!open.empty()) {
            return false;
        }
        return true;
    }
};


// Solution2 (My implementation)  [練習用 unordered_map]
class Solution {
public:
    bool isValid(string s) {
        stack<char> open;
        unordered_map<char,char> m = {{')','('}, {']','['}, {'}','{'}};
        // m.insert({')','('});
        // m.insert({']','['});
        // m.insert({'}','{'});
        for (int i=0; i<s.size(); i++)
        {
            if (m.find(s[i]) != m.end())
            // if (s[i]==')' || s[i]==']' || s[i]=='}')
            {
                if (open.empty()) {
                    return false;
                }
                if (s[i] == ')' && open.top() != '(') {
                    return false;
                }
                if (s[i] == ']' && open.top() != '[') {
                    return false;
                }
                if (s[i] == '}' && open.top() != '{') {
                    return false;
                }
                open.pop();
            } else {
                open.push(s[i]);
            }
        }
        if (!open.empty())
        {
            return false;
        }
        return true;
    }
};