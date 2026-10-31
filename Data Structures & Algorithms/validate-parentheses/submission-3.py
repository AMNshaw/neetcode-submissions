class Solution:
    def isValid(self, s: str) -> bool:
        hashmap = {
            '}' : '{',
            ']' : '[',
            ')' : '('
        }
        stack = []
        if s[0] in (')', '}', ']'):
            return False
        for ch in s:
            if ch not in (')', '}', ']'):
                stack.append(ch)
            else:
                if len(stack) > 0:
                    if hashmap[ch] == stack[-1]:
                        stack.pop()
                    else:
                        stack.append(ch)
            print(stack)
        if len(stack) == 0:
            return True
        return False