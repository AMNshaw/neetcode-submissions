class Solution:
    def isAnagram(self, s: str, t: str) -> bool:

        return sorted(s) == sorted(t)
        s_countArr = [0] * 52
        t_countArr = [0] * 52
        for c in s:
            if 'A' <= c <= 'Z':
                index = ord(c) - ord('A')
                s_countArr[index] += 1
            if 'a' <= c <= 'z':
                index = ord(c) - ord('a')
                s_countArr[index + 26] += 1
                
        for c in t:
            if 'A' <= c <= 'Z':
                index = ord(c) - ord('A')
                t_countArr[index] += 1
            if 'a' <= c <= 'z':
                index = ord(c) - ord('a')
                t_countArr[index + 26] += 1
        
        return (s_countArr == t_countArr) 
        