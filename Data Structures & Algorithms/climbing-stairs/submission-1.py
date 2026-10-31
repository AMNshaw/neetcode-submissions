class Solution:
    def climbStairs(self, n: int) -> int:

        self.cache = {}

        return self.count(n)
    
    def count(self, n: int):
        if n <= 3:
            return n
        if n in self.cache:
            return self.cache[n]
        
        self.cache[n] = self.count(n - 2) + self.count(n - 1)

        return self.cache[n]
        
    
    