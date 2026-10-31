class Solution:
    def isValid(self, s: str) -> bool:
        char_map = {'{' : '}', '(' : ')', '[' : ']'}

        result = []
        for c in s:
            if c in char_map:
                result.append(c)
                continue
            else:
                if not result or char_map[result[-1]] != c:
                    return False
            result.pop()

        return not result
