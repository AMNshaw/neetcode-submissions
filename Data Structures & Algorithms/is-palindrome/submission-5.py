import string
class Solution:
    def isPalindrome(self, s: str) -> bool:
        s = s.translate(str.maketrans('', '', string.punctuation))
        s = s.lower()
        s_ = s.replace(" ", "")
        
        if s_ == "":
            return True

        i = 0
        j = len(s_)-1
        while i < len(s_):
            print(f"i:{i}")
            print(f"j:{j}")
            print(f"i:{s_[i]}")
            print(f"j:{s_[j]}")
            if s_[i] == s_[j]:
                i += 1
                j -= 1
            else:
                return False
            
            if i >= j:
                return True
