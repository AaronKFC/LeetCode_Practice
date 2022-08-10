// Solution1
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> m;
        for (int i=0; i<strs.size(); i++) {
            string s_sort(strs[i]);
            sort(s_sort.begin(), s_sort.end());
            if (m.find(s_sort) == m.end()) {
                vector<string> s={strs[i]};
                m.insert({s_sort, s});
            } else {
                m[s_sort].push_back(strs[i]);
            }
        }
        vector<vector<string>> ans;
        unordered_map<string, vector<string>>::iterator iter;
        for (iter=m.begin(); iter!=m.end(); iter++) {
            ans.push_back(iter->second);
        }
        return ans;
    }
};

// Solution2 (NeetCode)
/*
    Given array of strings, group anagrams together (same letters diff order)
    Ex. strs = ["eat","tea","tan","ate","nat","bat"] -> [["bat"],["nat","tan"],["ate","eat","tea"]]

    Count chars, for each string use total char counts (naturally sorted) as key

    Time: O(n x l) -> n = length of strs, l = max length of a string in strs
    Space: O(n x l)
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        for (int i = 0; i < strs.size(); i++) {
            string key = getKey(strs[i]);
            m[key].push_back(strs[i]);
        }
        
        vector<vector<string>> result;
        for (auto it = m.begin(); it != m.end(); it++) {
            result.push_back(it->second);
        }
        return result;
    }
private:
    string getKey(string str) {
        vector<int> count(26);
        for (int j = 0; j < str.size(); j++) {
            count[str[j] - 'a']++;
        }
        
        string key = "";
        for (int i = 0; i < 26; i++) {
            key.append(to_string(count[i] + 'a'));
        }
        return key;
    }
};




