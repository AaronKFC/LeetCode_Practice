### Solution1 ###
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        anagram={}
        
        for s in strs:
            s_sort = [c for c in s]
            s_sort.sort()
            ss=''
            for c in s_sort:
                ss=ss+c
            s_sort=ss
            if s_sort not in anagram:
                anagram[s_sort] = [s]
            else:
                anagram[s_sort].append(s)
        groups = []
        for x in anagram:
            groups.append(anagram.get(x))
        
        return groups


### Solution2 (NeetCode) ###
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        ans = collections.defaultdict(list)

        for s in strs:
            count = [0] * 26
            for c in s:
                count[ord(c) - ord('a')] += 1
            ans[tuple(count)].append(s)
        return ans.values()
