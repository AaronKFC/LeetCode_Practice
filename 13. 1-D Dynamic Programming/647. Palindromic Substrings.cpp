/*
    Given a string, return # of palindromic substrings in it
    Ex. s = "babad" -> "bab", s = "cbbd" -> "bb"

    2 pointers, middle out, check both odd & even sized strings

    Time: O(n^2)
    Space: O(1)
*/

// Solution1 (My implementation)
class Solution {
public:
    int countSubstrings(string s) {
        for(int i=0; i<s.size(); i++) {
            midOut(s, i, i);
            midOut(s, i, i+1);
        }
        return result;
    }
private:
    int result = 0;
    void midOut(string s, int l, int r) {
        while(l>=0 && r<s.size() && s[l]==s[r]) {
            result++;
            l--;
            r++;
        }
    }
};