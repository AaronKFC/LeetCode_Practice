//solution1
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;
        
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        if (s==t)
            return true;
        return false;
        
    }
};

// Solution 2
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;
        
        unordered_map<char,int> Scnt;
        unordered_map<char,int> Tcnt;
        
        for (int i=0; i < s.size(); i++) {
            if (Scnt.find(s[i]) == Scnt.end()) {
                Scnt.insert({s[i],1});
            } else if (Scnt.find(s[i]) != Scnt.end()) {
                Scnt[s[i]]++;
            }
            if (Tcnt.find(t[i]) == Tcnt.end()) {
                Tcnt.insert({t[i],1});
            } else if (Tcnt.find(t[i]) != Tcnt.end()) {
                Tcnt[t[i]]++;
            }
        }
        return Scnt == Tcnt;
        
    }
};


// Solution3 (NeetCode)
/*
    Given 2 strings, return true if anagrams (same letters diff order)
    Ex. s = "anagram" & t = "nagaram" -> true, s = "rat" & t = "car" -> false

    Count chars, strings should have same # of chars if anagram

    Time: O(n)
    Space: O(26)
*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        
        vector<int> count(26);
        
        for (int i = 0; i < s.size(); i++) {
            count[s[i] - 'a']++;
        }
        
        for (int j = 0; j < t.size(); j++) {
            count[t[j] - 'a']--;
            if (count[t[j] - 'a'] < 0) {
                return false;
            }
        }
        return true;
    }
};