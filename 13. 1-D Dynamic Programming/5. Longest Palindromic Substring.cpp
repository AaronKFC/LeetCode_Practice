/*
    Given a string s, return the longest palindromic substring in s
    Ex. s = "babad" -> "bab", s = "cbbd" -> "bb"

    Expand around center, extend as far as possible, store max length

    Time: O(n^2)
    Space: O(1)
*/
// Solution1 (My implementation) Similar to NeetCode python solution
class Solution {
public:
    string longestPalindrome(string s) {
        string res="";
        int sLen = s.size();
        int resLen=0;
        
        for (int i=0; i<sLen; i++) {
            
            // odd length of s
                int l=i, r=i;
                while (l>=0 && r<sLen && s[l]==s[r]) {
                    if (r-l+1 > resLen) {
                        resLen = r-l+1;
                        res = s.substr(l,resLen);
                    }
                    l--;
                    r++;
                }
            
            // even length of s
                l=i; 
                r=i+1;
                while (l>=0 && r<sLen && s[l]==s[r]) {
                    if (r-l+1 > resLen) {
                        resLen = r-l+1;
                        res = s.substr(l,resLen);
                    }
                    l--;
                    r++;
                }
        }
        return res;
    }
};

// Solution2 (NeetCode)
class Solution {
public:
    string longestPalindrome(string s) {
        int maxStart = 0;
        int maxLength = 1;
        
        for (int i = 0; i < s.size() - 1; i++) {
            middleOut(s, i, i, maxStart, maxLength);
            middleOut(s, i, i + 1, maxStart, maxLength);
        }
        
        return s.substr(maxStart, maxLength);
    }
private:
    void middleOut(string s, int i, int j, int& maxStart, int& maxLength) {
        while (i >= 0 && j <= s.size() - 1 && s[i] == s[j]) {
            i--;
            j++;
        }
        if (j - i - 1 > maxLength) {
            maxStart = i + 1;
            maxLength = j - i - 1;
        }
    }
};