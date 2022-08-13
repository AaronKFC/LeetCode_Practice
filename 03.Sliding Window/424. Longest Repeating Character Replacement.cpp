
/*
    Given a string s & an int k, can change any char k times:
    Return length of longest substring containing same letter
    Ex. s = "ABAB" k = 2 -> 4 "AAAA", s = "AABABBA" k = 1 -> 4

    Sliding window, expand if can change char, contract if > k

    Time: O(n)
    Space: O(26)
*/

//Solution 1 (NeetCode)

class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26);
        int l=0;
        int r=0;
        int result=0;
        int maxF=0;
        for (r; r<s.size(); r++) {
        // while (r<s.size()) {
            count[s[r] - 'A']++;
            maxF = max(maxF, count[s[r]-'A']);
            if ((r-l+1 - maxF) > k) {
                count[s[l] - 'A']--;
                l++;
            }
            result = max(result, r-l+1);
            // r++;
        }
        return result;
    }
};
